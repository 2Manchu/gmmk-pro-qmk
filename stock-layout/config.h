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

//Disable RGB in sleep, enable advanced effects
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_KEYPRESSES            // Enables REACTIVE & SPLASH modes
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS   // Enables Heatmap, Rain

#define RGBLIGHT_HUE_STEP 7             // The number of steps to cycle through the hue by (default 10)
#define RGBLIGHT_SAT_STEP 4             // The number of steps to increment the saturation by (default 17)
#define RGBLIGHT_VAL_STEP 7             // The number of steps to increment the brightness by (default 17)

//Default mode and color options for QMK built in effects
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINBOW_PINWHEELS // Sets the default effect mode, if none has been set
#define RGB_MATRIX_DEFAULT_HUE 115                           // Sets the default hue value, if none has been set
#define RGB_MATRIX_DEFAULT_SAT 255                           // Sets the default saturation value, if none has been set
#define RGB_MATRIX_DEFAULT_VAL 255                           // Sets the default brightness value, if none has been set
#define RGB_MATRIX_DEFAULT_SPD 80

//These effects seem to break the layer highlighting for some reason
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH

#define FORCE_NKRO
