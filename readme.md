# Custom QMK Firmware for GMMK Pro

## Background

This is my personal QMK setup for my GMMK Pro ANSI Rev 1.0. I was very unimpressed with the Glorious software in terms of key and layer customization, namely the fact that you can't do a momentary layer switch while holding a key down. I also found it annoying that you can't have RGB effects on the side LEDs while disabling the top LEDs, as my keycaps do not have translucent legends and I just do not like the aesthetic.

## Feature Overview

This repository has two keymaps, one for my personal preferred layout, and one with the stock GMMK Pro layout. The first layer contains a few essential extras, including media keys, a numpad with num lock toggle, and a reboot to bootloader switch. Keys on the first layer are custom-backlit to help identify their functions and locations. Each keymap can control QMK RGB effects, including mode, hue, saturation, and brightness. There is the option to enable RGB effects on only the side lighting while leaving the top blank. I have also included one additional lighting mode, which is a solid user-defined color on only the sides, with the same HSB customization as before. The user-defined mode uses separate memory, so you can have a different HSB set in the user mode versus the QMK RGB mode, and toggle between the two with just a button. These customzations can optionally be saved to the keyboard's EEPROM, with the exception of the user-defined mode settings.

## Usage and Controls

Credit to [jwhurley1](https://github.com/jwhurley1) for the encoder idea that I've incorporated into my keymap. My firmware has three different lighting types. All adjustments of modes, lighting speed, and HSB values within the types are done by rotating the encoder clockwise and anti-clockwise, but available controls vary slightly depending on the lighting type selected, and some are done with an encoder click instead of rotation. RGB controls are also illuminated when pressing the Fn key.

| Type                | Description |
| -----------         | ----------- |
| QMK_FANCY_ALL       | QMK built-in RGB effects (rainbow, reactive, etc) displayed on all keys and side LEDs |
| QMK_FANCY_SIDE      | QMK built-in RGB effects (rainbow, reactive, etc) displayed on only the side LEDs     |
| USER_SOLID_SIDE     | User-defined solid color displayed on only the side LEDs                              |

### For `QMK_FANCY_*` lighting types:

| Key Combo                   | Lighting action taken                                                           |
| -----------                 | -----------                                                                     |
| Left Shift                  | Scroll through QMK RGB lighting effects (rainbow, reactive, etc)                |
| Left Control                | Increase/decrease hue (color) value for selected effect                         |
| Left Alt                    | Increase/decrease saturation value for selected effect                          |
| Left Control + Alt          | Increase/decrease brightness value for selected effect                          |
| Right Shift                 | Increase/decrease speed for moving/reactive RGB, gradient width for static RGB  |
| Left Shift + Encoder Press  | Toggle all lighting on/off (persists after power loss)                          |
| Right Ctrl + Encoder Press  | Save selected effect, HSB, and speed to EEPROM (persists after power loss)      |

### For `USER_SOLID_SIDE` lighting type:

| Key Combo                   | Lighting action taken                                                           |
| -----------                 | -----------                                                                     |
| Left Control                | Increase/decrease hue (color) value for selected effect                         |
| Left Alt                    | Increase/decrease saturation value for selected effect                          |
| Left Control + Alt          | Increase/decrease brightness value for selected effect                          |
| Left Shift + Encoder Press  | Toggle all lighting on/off (persists after power loss)                          |

### To access the 3 types of lighting:

| Key Combo                   | Lighting type selected                                                                    |
| -----------                 | -----------                                                                               |
| Left Ctrl + Encoder Press   | Toggle between `USER_SOLID_SIDE` and `QMK_FANCY_ALL`. Initial press defaults to user      |
| Left Alt + Encoder Press    | Toggle between `QMK_FANCY_SIDE` and `QMK_FANCY_ALL`. Initial press defaults to fancy side |

Additionally, these are the actions found on layer 1 of the keymap.

### Layer 1 key functions:

| Fn + ...          | Action taken                                                                            |
| -----------       | -----------                                                                             |
| W                 | Stop media playback                                                                     |
| S                 | Play/pause media playback                                                               |
| A/D               | Previous/next track, respectively                                                       |
| P                 | Toggle num lock                                                                         |
| V,B,N,G,H,J,T,Y,U | Numpad keys 1-9, respectively                                                           |
| \                 | Reboot keyboard to DFU mode (QK_BOOT)                                                   |

## How to Install

First, a disclaimer:  
*By installing this firmware, you agree to the following: I will not be held responsible for any damage or issues that may directly or indirectly result from you deciding to flash and use this firmware. This firmware was written for the ANSI Rev 1.0 GMMK Pro PCB. Use on other versions at your own risk.*

* Download and install the latest [QMK Toolbox installer](https://github.com/qmk/qmk_toolbox) and either the `-custom-tonym.bin` or `-stock-tonym.bin` from this repo. This will allow you to flash the custom firmware.
* Open QMK Toolbox, then put your keyboard into DFU mode. If you are on the stock Glorious firmware, hold `Space + B` while plugging in the keyboard. If you are on the VIA firmware, hold `Esc` while plugging in the keyboard.
* You will see a yellow line in QMK Toolbox that indicates it has found a device in DFU mode if all was successful, and the `Flash` button should become available. Select the .bin file you downloaded earlier. Press `Flash`. You should see a progress bar where it erases and flashes the new firmware. Do not disconnect the board during this process. The board will automatically reboot into user mode when done. If successful, you should see rainbow mode on only the side LEDs. In that case, you are done.

If you are (understandably) not comfortable flashing a firmware from some random guy on the internet, you can view and compile the firmware from source using the tips below.

## Editing

To make edits and compile from source, follow the guide below:

* https://docs.qmk.fm/#/newbs

In short:
* Install QMK_MSYS, and make sure you download the firmware repo as part of it
* Download either the `stock-layout` or `custom-layout` folder from this repo, and place it at `..\qmk_firmware\keyboards\gmmk\pro\rev1\ansi\keymaps`. You can rename the folder to your liking.
* Execute the following in QMK_MSYS:
  * `qmk config user.keyboard=gmmk/pro/rev1/ansi`
  * `qmk config user.keymap=[what you named the folder from the last step]`
* Edit `keymap.c` to change lighting and key layouts. Edit `config.h` to enable/disable QMK effects and set some other defaults. Add/modify other files as necessary.
* Compile and flash the firmware.