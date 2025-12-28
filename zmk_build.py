#!/usr/bin/env python3
import subprocess
import yaml
import os
import sys
import shutil
from pathlib import Path

# --- Configuration ---
DOCKER_IMAGE = "zmkfirmware/zmk-build-arm:stable"
CACHE_VOLUME = "zmk-source-cache-urchin"
OUTPUT_DIR = "build_output"
BUILD_YAML = "build.yaml"

def run_docker_build(targets):
    """Triggers the Docker container with the fixed workspace logic."""

    # Ensure local output directory exists and is writable
    if not os.path.exists(OUTPUT_DIR):
        os.makedirs(OUTPUT_DIR)

    # The Build Commands (Executed inside the container)
    # 1. We clear the internal config to ensure it's a fresh copy of your local changes
    # 2. We initialize west inside /build pointing to our local config
    # 3. We run the build from the /build/zmk/app folder

    build_scripts = [
        "rm -rf /build/config",
        "cp -r /src/config /build/config",
        "cd /build",
        "if [ ! -d '.west' ]; then west init -l config; fi",
        "west update",
        "west zephyr-export"
    ]

    for t in targets:
        board = t['board']
        shield = t.get('shield', '')
        # Handle shield arguments (e.g. urchin_left nice_view_adapter)
        shield_arg = f"-DSHIELD='{shield}'" if shield else ""

        # Determine output filename based on shield or board
        name_base = shield.split()[0] if shield else board

        # Build command: note we point ZMK_CONFIG to the internal /build/config
        cmd = (
            f"echo '--- Building {name_base} ---' && "
            f"west build -p always -b {board} zmk/app -- {shield_arg} -DZMK_CONFIG='/build/config' && "
            f"cp build/zephyr/zmk.uf2 /out/{name_base}.uf2"
        )
        build_scripts.append(cmd)

    # Join all commands with '&&' so it stops if any step fails
    full_script = " && ".join(build_scripts)

    docker_cmd = [
        "docker", "run", "--rm",
        "-v", f"{CACHE_VOLUME}:/build",      # Persistent ZMK/Zephyr source
        "-v", f"{os.getcwd()}:/src:ro",      # Your repo (Read-Only)
        "-v", f"{os.getcwd()}/{OUTPUT_DIR}:/out", # Your output folder (Writable)
        "-w", "/build",                      # Work inside the volume
        DOCKER_IMAGE,
        "/bin/bash", "-c", full_script
    ]

    print(f"--- Starting Build for {len(targets)} targets ---")
    print(f"--- Cache Volume: {CACHE_VOLUME} ---")

    try:
        process = subprocess.run(docker_cmd, check=True)
        return process.returncode
    except subprocess.CalledProcessError as e:
        print(f"\n[!] Docker build failed with exit code {e.returncode}")
        return e.returncode
    except Exception as e:
        print(f"\n[!] Unexpected error: {e}")
        return 1

def main():
    # 1. Load build.yaml
    if not os.path.exists(BUILD_YAML):
        print(f"Error: {BUILD_YAML} not found in current directory.")
        sys.exit(1)

    try:
        with open(BUILD_YAML, 'r') as f:
            data = yaml.safe_load(f)
            targets = data.get('include', [])
    except Exception as e:
        print(f"Error parsing {BUILD_YAML}: {e}")
        sys.exit(1)

    if not targets:
        print(f"No build targets found in {BUILD_YAML}. Check your 'include' list.")
        sys.exit(1)

    # 2. Mode selection
    if "--hook" in sys.argv:
        # Pre-commit Hook Mode: Fast syntax check only
        print("--- Pre-commit Check ---")
        if os.path.exists("config") and os.path.exists(BUILD_YAML):
            print("✓ Project structure valid.")
            sys.exit(0)
        else:
            print("✗ Project structure invalid. Missing 'config/' or 'build.yaml'.")
            sys.exit(1)

    # 3. Execution Mode: Full Docker Build
    exit_code = run_docker_build(targets)

    if exit_code == 0:
        print(f"\n[✓] Build Successful! Files in ./{OUTPUT_DIR}")
    else:
        print(f"\n[✗] Build Failed.")

    sys.exit(exit_code)

if __name__ == "__main__":
    main()

