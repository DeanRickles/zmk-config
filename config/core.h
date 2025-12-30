#pragma once
// Config in order of dependancies.
#include <behaviors.dtsi>              /* Can't remember what this is for. */
#include <behaviors/mouse_keys.dtsi>   /* Base mouse movement keys. */
#include <dt-bindings/zmk/bt.h>        /* ZMK Bluetooth helper. */
#include <dt-bindings/zmk/keys.h>      /* ZMK Key names. */
#include <dt-bindings/zmk/mouse.h>     /* ZMK Mouse movement. */
#include <dt-bindings/zmk/outputs.h>   /* Not sure what this is used for. Mouse I think. */
#include "zmk-helpers/helper.h"        /* Base ZMK helper fuctions. */
#include "zmk-helpers/key-labels/34.h" /* Used so Combos knows where the keys are. */
#include "constants.h"                 /* Personalised Layer/base names. */
#include "simple-keys.h"               /* Personalised key names. */
#include "behaviors/combos.dtsi"       /* Personalised Combo keys. */
#include "behaviors/mouse.dtsi"        /* Personalised Mouse movement settings. */
#include "behaviors/soft-off.dtsi"     /* Base Soft-off setting. */

