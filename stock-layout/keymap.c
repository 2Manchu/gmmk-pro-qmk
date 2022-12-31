/* Copyright 2022 2Manchu <42014390+2Manchu@users.noreply.github.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Per-key LED enum and RGB-control related defines
#include "rgb_utils.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    //Numpad bottom row looks off but is correct
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, KC_MSTP, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, KC_NUM , _______, _______, QK_BOOT,          _______,
        CW_TOGG, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),


};
// clang-format on

//Set power-up defaults for lighting
void keyboard_post_init_user(void) {
    //Initialize default user-configurable HSV values
    user_hsv.h = 115;
    user_hsv.s = 255;
    user_hsv.v = 255;

    //Initialize bools for function layer illumination behavior
    do_reset = false;
    first_press = true;

    //Set the default lighting mode for the keyboard when it powers up. See rgb_utils.h for all lighting modes available
    LIGHTING_MODE = QMK_FANCY_SIDE;
}

//Write current QMK RGB settings to EEPROM
void save_qmk_rgb_settings(void) {
    rgb_matrix_mode(rgb_matrix_get_mode());
    rgb_matrix_set_speed(rgb_matrix_get_speed());
    rgb_matrix_sethsv(rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val());
}

// Sets Row 4 (caps row) to red when caps lock is enabled
void set_caps_row_led(bool caps_on) {
    if (caps_on) {
        for (uint8_t curr_led = 0; curr_led < CAPS_LED_NUM; curr_led++) {
            rgb_matrix_set_color(LEDS_LIST_CAPS[curr_led], RGB_RED);
        }
    } else {
        for (uint8_t curr_led = 0; curr_led < CAPS_LED_NUM; curr_led++) {
            rgb_matrix_set_color(LEDS_LIST_CAPS[curr_led], RGB_BLACK);
        }
    }
}

void set_rgb_mode(bool clockwise) {
    //Not writing to eeprom, so user will need to manually save settings with RCTL + knob click
    if (clockwise) {
        rgb_matrix_step_noeeprom();
    }
    else {
        rgb_matrix_step_reverse_noeeprom();
    }
}

void set_rgb_speed(bool clockwise) {
    if (clockwise) {
        rgb_matrix_increase_speed_noeeprom();
    }
    else {
        rgb_matrix_decrease_speed_noeeprom();
    }
}

void adjust_user_lighting_hsv(bool clockwise, uint8_t hue, uint8_t sat, uint8_t val) {
    if (clockwise) {
        //Check bounds for all except hue
        user_hsv.h += hue;

        if (user_hsv.s + sat > 255) {
            user_hsv.s = 255;
        }
        else {
            user_hsv.s += sat;
        }
        if (user_hsv.v + val > 255) {
            user_hsv.v = 255;
        }
        else {
            user_hsv.v += val;
        }
    }
    else {
        user_hsv.h -= hue;

        if (user_hsv.s - sat < 0) {
            user_hsv.s = 0;
        }
        else {
            user_hsv.s -= sat;
        }
        if (user_hsv.v - val < 0) {
            user_hsv.v = 0;
        }
        else {
            user_hsv.v -= val;
        }
    }
}

void adjust_qmk_effect_hsv(bool clockwise, bool adj_hue, bool adj_sat, bool adj_val) {
    //Adjusts QMK lighting (not user-defined side lighting) by the default RGBLIGHT_*_STEP values, defined in config.h
    if (clockwise) {
        if (adj_hue) {
            rgb_matrix_increase_hue_noeeprom();
        }
        else if (adj_sat) {
            rgb_matrix_increase_sat_noeeprom();
        }
        else if (adj_val) {
            rgb_matrix_increase_val_noeeprom();
        }
    }
    else {
        if (adj_hue) {
            rgb_matrix_decrease_hue_noeeprom();
        }
        else if (adj_sat) {
            rgb_matrix_decrease_sat_noeeprom();
        }
        else if (adj_val) {
            rgb_matrix_decrease_val_noeeprom();
        }
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    //If we're above the base layer then do special illumination for certain keys
    if (get_highest_layer(layer_state) > 0) {
        uint8_t curr_layer = get_highest_layer(layer_state);

        //Disable LEDs temporarily while Fn is pressed
        if (first_press) {
            last_hsv = rgb_matrix_get_hsv();
            rgb_matrix_sethsv_noeeprom(HSV_BLACK);
            first_press = false;
            do_reset = true;
        }

        // Illuminate specific layer 1 and RGB keys when Fn is pressed
        switch (curr_layer) {
            case 1:
            //Media controls
            rgb_matrix_set_color(LED_S, RGB_GOLD);
            rgb_matrix_set_color(LED_A, RGB_SPRINGGREEN);
            rgb_matrix_set_color(LED_D, RGB_SPRINGGREEN);
            rgb_matrix_set_color(LED_W, RGB_GOLD);

            //Bootloader key
            rgb_matrix_set_color(LED_BSLS, RGB_MAGENTA);

            //RGB controls
            rgb_matrix_set_color(LED_LSFT, RGB_RED);
            rgb_matrix_set_color(LED_LCTL, RGB_GREEN);
            rgb_matrix_set_color(LED_LWIN, RGB_BLUE);
            rgb_matrix_set_color(LED_RSFT, RGB_PINK);
            rgb_matrix_set_color(LED_RCTL, RGB_AZURE);

            //Virtual numpad
            rgb_matrix_set_color(LED_T, RGB_WHITE);
            rgb_matrix_set_color(LED_Y, RGB_WHITE);
            rgb_matrix_set_color(LED_U, RGB_WHITE);
            rgb_matrix_set_color(LED_G, RGB_WHITE);
            rgb_matrix_set_color(LED_H, RGB_WHITE);
            rgb_matrix_set_color(LED_J, RGB_WHITE);
            rgb_matrix_set_color(LED_V, RGB_WHITE);
            rgb_matrix_set_color(LED_B, RGB_WHITE);
            rgb_matrix_set_color(LED_N, RGB_WHITE);

            //Num lock - white when off, red when on
            if (host_keyboard_led_state().num_lock) {
                rgb_matrix_set_color(LED_P, RGB_RED);
            }
            else {
                rgb_matrix_set_color(LED_P, RGB_WHITE);
            }

            //Caps word key
            rgb_matrix_set_color(LED_CAPS, RGB_WHITE);
        }
    }
    //Back in layer 0
    else {
        //Restore RGB settings when out of function layer
        if (do_reset) {
            rgb_matrix_sethsv_noeeprom(last_hsv.h, last_hsv.s, last_hsv.v);
            first_press = true;
            do_reset = false;
        }

        //Turn off top LEDs and leave QMK RGB effects on the side configurable as normal with RGB mode buttons
        //Unfortunately these options do not persist after power loss due to the fact that the rgb_matrix_set function does not write to EEPROM
        //Static user color and mode will have to be reset manually in that case
        if (LIGHTING_MODE == QMK_FANCY_SIDE) {
            for (uint8_t i = 0; i < NUM_KEYS; i++) {
                rgb_matrix_set_color(LEDS_NOT_SIDE[i], RGB_BLACK);
            }
        }
        else if (LIGHTING_MODE == USER_SOLID_SIDE) {
            RGB user_rgb = hsv_to_rgb(user_hsv);
            for (uint8_t i = 0; i < SIDE_LEDS_NUM; i++) {
                rgb_matrix_set_color(LEFT_SIDE_RGB[i], user_rgb.r, user_rgb.g, user_rgb.b);
                rgb_matrix_set_color(RIGHT_SIDE_RGB[i], user_rgb.r, user_rgb.g, user_rgb.b);
            }
        }

        //Caps lock LED
        if (host_keyboard_led_state().caps_lock) {
            set_caps_row_led(true);
        } else {
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
                set_caps_row_led(false);
            }
        }
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //Credit to GitHub user @jwhurley1 for this trick
        //Relies on the volume knob press being bound to KC_MUTE
        //Incidentally, any other keys set to KC_MUTE will also trigger this if CTRL is pressed simultaneously
        case KC_MUTE:
            if (record -> event.pressed) {
                if (get_mods() & MOD_BIT(KC_LCTL)) {
                    //Toggle main keys lighting and solid user-defined side lighting
                    if (LIGHTING_MODE == USER_SOLID_SIDE) {
                        LIGHTING_MODE = QMK_FANCY_ALL;
                        //Set back to previous HSV setting when user option is turned off
                        rgb_matrix_sethsv_noeeprom(last_hsv.h, last_hsv.s, last_hsv.v);
                    }
                    else {
                        LIGHTING_MODE = USER_SOLID_SIDE;
                        //Retain current hue and sat, but set brightness to 0 while in this mode
                        last_hsv = rgb_matrix_get_hsv();
                        rgb_matrix_sethsv_noeeprom(HSV_BLACK);
                    }
                    return false;
                }
                else if (get_mods() & MOD_BIT(KC_LALT)) {
                    //Check for user side lighting enabled and disable if necessary
                    if (LIGHTING_MODE == USER_SOLID_SIDE) {
                        //Make sure we set the last HSV value back otherwise we end up with nothing if switching from user -> fancy mode
                        rgb_matrix_sethsv_noeeprom(last_hsv.h, last_hsv.s, last_hsv.v);
                    }

                    //Toggle main keys lighting but leave the built-in QMK RGB effects active on the side
                    if (LIGHTING_MODE == QMK_FANCY_SIDE) {
                        LIGHTING_MODE = QMK_FANCY_ALL;
                    }
                    else {
                        LIGHTING_MODE = QMK_FANCY_SIDE;
                    }
                    return false;
                }
                else if (get_mods() & MOD_BIT(KC_LSFT)) {
                    //Toggle RGB on/off
                    rgb_matrix_toggle();
                    return false;
                }
                //Save the current QMK effect HSV settings to EEPROM
                else if (get_mods() & MOD_BIT(KC_RCTL)) {
                    save_qmk_rgb_settings();
                    return false;
                }
                //If KC_MUTE received but CTRL or ALT (exclusively) not pressed
                return true;
            }
        default:
            return true; // Process all other keycodes normally
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t current_mods = get_mods();

    //Adjust RGB settings depending on modifier keys and lighting type active at time of encoder action
    if (LIGHTING_MODE == USER_SOLID_SIDE) {
        if ((current_mods & MOD_BIT(KC_LCTL)) && (current_mods & MOD_BIT(KC_LALT))) {
            adjust_user_lighting_hsv(clockwise, 0, 0, RGBLIGHT_VAL_STEP);
            return false;
        }
        else if (current_mods & MOD_BIT(KC_LCTL)) {
            adjust_user_lighting_hsv(clockwise, RGBLIGHT_HUE_STEP, 0, 0);
            return false;
        }
        else if (current_mods & MOD_BIT(KC_LALT)) {
            adjust_user_lighting_hsv(clockwise, 0, RGBLIGHT_SAT_STEP, 0);
            return false;
        }
        else {
            if (clockwise) {
                tap_code16(KC_VOLU);
            } else {
                tap_code16(KC_VOLD);
            }
        }
    }
    //Not in user defined solid mode
    else {
        if (current_mods & MOD_BIT(KC_LSFT)) {
            set_rgb_mode(clockwise);
            return false;
        }
        else if (current_mods & MOD_BIT(KC_RSFT)) {
            set_rgb_speed(clockwise);
            return false;
        }
        //HSV controls for built in QMK effects. Changes are not saved until the user presses RCTL + Knob click to reduce EEPROM writes
        if ((current_mods & MOD_BIT(KC_LCTL)) && (current_mods & MOD_BIT(KC_LALT))) {
            adjust_qmk_effect_hsv(clockwise, false, false, true);
            return false;
        }
        else if (current_mods & MOD_BIT(KC_LCTL)) {
            adjust_qmk_effect_hsv(clockwise, true, false, false);
            return false;
        }
        else if (current_mods & MOD_BIT(KC_LALT)) {
            adjust_qmk_effect_hsv(clockwise, false, true, false);
            return false;
        }
        else {
            if (clockwise) {
                tap_code16(KC_VOLU);
            } else {
                tap_code16(KC_VOLD);
            }
        }
    }

    return true;
}
