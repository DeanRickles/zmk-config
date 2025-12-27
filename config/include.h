#include <behaviors.dtsi>
#include <behaviors/mouse_keys.dtsi>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/mouse.h>
#include <dt-bindings/zmk/outputs.h>

#include "zmk-helpers/helper.h"
#include "zmk-helpers/key-labels/34.h"

#define HOST_OS LINUX // Needed for unicode international_chars
#include "constants.h"
#include "custom-keys.h"
#include "../behaviors/combos.dtsi"
#include "../behaviors/mouse.dtsi"
#include "../behaviors/soft-off.dtsi"
