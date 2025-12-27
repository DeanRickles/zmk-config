#pragma once

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
#define MOU_BSPC  &lt MOU BSPC

/*Custom keys - volume */
#define VOL_U &kp C_VOL_UP
#define VOL_M &kp C_MUTE
#define VOL_D &kp C_VOL_DN
/*Custom keys - brightness */
#define BRI_U &kp C_BRI_UP
#define BRI_D &kp C_BRI_DN

/* Characters - Alpha */
#define _A_ &kp A
#define _B_ &kp B
#define _C_ &kp C
#define _D_ &kp D
#define _E_ &kp E
#define _F_ &kp F
#define _G_ &kp G
#define _H_ &kp H
#define _I_ &kp I
#define _J_ &kp J
#define _K_ &kp K
#define _L_ &kp L
#define _M_ &kp M
#define _N_ &kp N
#define _O_ &kp O
#define _P_ &kp P
#define _Q_ &kp Q
#define _R_ &kp R
#define _S_ &kp S
#define _T_ &kp T
#define _U_ &kp U
#define _V_ &kp V
#define _W_ &kp W
#define _X_ &kp X
#define _Y_ &kp Y
#define _Z_ &kp Z

/* Characters - Numbers */
#define _0_ &kp N0
#define _1_ &kp N1
#define _2_ &kp N2
#define _3_ &kp N3
#define _4_ &kp N4
#define _5_ &kp N5
#define _6_ &kp N6
#define _7_ &kp N7
#define _8_ &kp N8
#define _9_ &kp N9

/* Characters - Functions */
#define _F1_  &kp F1
#define _F2_  &kp F2
#define _F3_  &kp F3
#define _F4_  &kp F4
#define _F5_  &kp F5
#define _F6_  &kp F6
#define _F7_  &kp F7
#define _F8_  &kp F8
#define _F9_  &kp F9
#define _F10_ &kp F10
#define _F11_ &kp F11
#define _F12_ &kp F12

/* Characters - Symbols */
#define _SLASH_ &kp SLASH  /* / */
#define _BSLH_  &kp NUBS   /* \ */
#define _DOT_   &kp DOT    /* . */
#define _COMMA_ &kp COMMA  /* , */
#define _QUOT_  &kp QUOT   /* ' */
#define _SEMI_  &kp SEMI   /* ; */
#define _LPAR_  &kp LPAR   /* ( */
#define _RPAR_  &kp RPAR   /* ) */
#define _LBRC_  &kp LBRC   /* { */
#define _RBRC_  &kp LBRC   /* } */
#define _LBKT_  &kp LBKT   /* [ */
#define _RBKT_  &kp RBKT   /* ] */
#define _MINUS_ &kp MINUS  /* - */
#define _EQUAL_ &kp EQUAL  /* = */
#define _GRAVE_ &kp GRAVE  /*   */
#define _STAR_  &kp STAR   /* * */
#define _PLUS_  &kp PLUS   /* + */
#define _UNDER_ &kp UNDER  /* _ */
#define _SQT_   &kp SQT    /* ' */
#define _DLLR_  &kp DLLR   /* $ */
#define _COLON_ &kp COLON  /* : */
#define _QMARK_ &kp QMARK  /* ? */
#define _PRCNT_ &kp PRCNT  /* % */
#define _PND_   &kp LC(N3) /* £ */
#define _PND_   &kp LC(N3) /* £ */
#define _DQT_   &kp DQT    /*   */
#define _EXCL_  &kp EXCL   /*   */
#define _HASH_  &kp HASH   /* # */
#define _TILDE_ &kp TILDE  /*   */
#define _AMPS_  &kp AMPS   /*   */
#define _CARET_ &kp CARET  /*   */

/* Navidation */
#define _UP_    &kp UP
#define _DOWN_  &kp DOWN
#define _LEFT_  &kp LEFT
#define _RIGHT_ &kp RIGHT
#define _HOME_  &kp HOME
#define _END_   &kp END
#define _PG_UP_ &kp PG_UP
#define _PG_DN_ &kp PG_DN

/* Utilities */
#define _INS_   &kp INS
#define _ESC_   &kp ESC
#define _SLCK_  &kp SLCK
#define _PSCRN_ &kp PSCRN
#define _SPACE_ &kp SPACE
#define _ENTER_ &kp ENTER
#define _TAB_   &kp TAB
#define _BSPC_  &kp BSPC
#define _LBSPC_ &kp LC(BSPC) /* Ctrl + backspace */
#define _DEL_   &kp DEL
#define _NLCK_  &kp LNLCK    /* number lock */

#define _COPY_  &kp LC(C)
#define _PASTE_ &kp LC(V)
#define _CUT_   &kp LC(X)
#define _UNDO_  &kp LC(Z)
