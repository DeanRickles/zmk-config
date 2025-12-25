#pragma once

/* Keys */
#define ___ &trans
#define XXX &none

/* OS */
#define WINDOWS 0
#define LINUX   1
#define MAC_OS  2

/*  Layers -Must match order in which they are defined */
#define COL 0
#define MOU 1
#define NUM 2
#define SYM 3
#define NAV 4
#define FNC 5

/* Modifier keys */
#define GL LGUI
#define CL LCTRL
#define AL LALT
#define SL LSHFT
#define GR RGUI
#define CR RCTRL
#define AR RALT
#define SR RSHFT

/* Bluetooth keys */
#define BTS0  &bt BT_SEL 0
#define BTS1  &bt BT_SEL 1
#define BTS2  &bt BT_SEL 2
#define BTS3  &bt BT_SEL 3
#define BTCLR &bt BT_CLR

/* Custom keys */
#define BL        &bootloader
#define SL_SPACE  &mt SL SPACE
#define NUM_ENTER &lt NUM ENTER
#define MOU_BSPC  &to_kp MOU BSPC

/*Custom keys - volume */
#define VOL_U     &kp C_VOL_UP
#define VOL_M     &kp C_MUTE
#define VOL_D     &kp C_VOL_DN
/*Custom keys - brightness */
#define BRI_U     &kp C_BRI_UP
#define BRI_D     &kp C_BRI_DN


