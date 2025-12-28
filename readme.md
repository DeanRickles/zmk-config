# ZMK Config

ZMK firmware configuration for Urchin keyboards, optimized for
English/Programming.

TODO: Add image of keyboad here.
![My Urchin 34 keys keyboard](images/urchin.jpg)

## Features

- QWERTY, [Colemak-DH](https://colemakmods.github.io/mod-dh/)
- Mouse keys support
- Cursor/Scroll toggle, DPI cycling and bootloader mode keybindings
- Nice!View Urchin animation on right side of Urchin (credits: [GPeye](https://github.com/gpeye/urchin-peripheral-animation))

## Keymap

TODO: Add image of keymap diagram here.
![Keymap drawing of all layers and combos](images/keymaps/urchin_keymap.svg)
TODO: Add link to copy/edit keymap here.

For more details, head to the [urchin.keymap](config/urchin.keymap)

## Behaviors

The keymap uses a few behaviors in order to make everything work:

- [Combos](behaviors/combos.dtsi)
- [Hold-Tap (Home Row Mods)](behaviors/hold-tap.dtsi)
- [Macros](behaviors/macros.dtsi)
- [Mod-Morph](behaviors/mod-morph.dtsi)

## References

- [Urchin Keyboard](https://github.com/duckyb/urchin)

# ZMK Local Docker Builder

This repository includes a custom Python utility (`zmk_build.py`) designed to build ZMK firmware locally using Docker. It replicates the official ZMK GitHub Actions environment while keeping your local repository 100% clean.

## Features

- **Zero-Touch Repo:** Your project folder is mounted as Read-Only. No residual `.west`, `zmk/`, or `modules/` folders are created in your directory.
- **High Performance:** Uses a persistent Docker volume to cache the ZMK source code and Zephyr RTOS, making subsequent builds significantly faster.
- **GitHub Parity:** Uses the official `zmkfirmware/zmk-build-arm:stable` image.
- **Pre-commit Ready:** Can be integrated into your git workflow to validate configurations before committing.

## Prerequisites

1.  **Docker:** [Install Docker for Ubuntu](https://docs.docker.com/engine/install/ubuntu/).
2.  **Permissions:** Ensure your user is in the `docker` group: `sudo usermod -aG docker $USER` (re-log after running).
3.  **Python 3:** With the `PyYAML` library installed: `pip install pyyaml`.

## Project Structure

The script expects the following layout:

```text
.
├── config/              # Your keymaps, west.yml, and conf
├── build.yaml           # ZMK Build Matrix
└── zmk_build.py         # The build script

```
