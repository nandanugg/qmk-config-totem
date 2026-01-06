<picture>
  <source media="(prefers-color-scheme: dark)" srcset="/docs/images/TOTEM_logo_dark.svg">
  <source media="(prefers-color-scheme: light)" srcset="/docs/images/TOTEM_logo_bright.svg">
  <img alt="TOTEM logo font" src="/docs/images/TOTEM_logo_bright.svg">
</picture>

# QMK CONFIG FOR THE TOTEM SPLIT KEYBOARD

> **Note**
> The qmk firmware for the TOTEM should work, but I haven't tested it yet. So if problems occur please contact me.

[Here](https://github.com/GEIGEIGEIST/totem) you can find the hardware files and build guide.\
[Here](https://github.com/GEIGEIGEIST/zmk-config-totem) you can find the ZMK config for the TOTEM.

TOTEM is a 38 key column-staggered split keyboard running [QMK](https://docs.qmk.fm/) or [ZMK](https://zmk.dev/). It's meant to be used with a SEEED XIAO RP2040 or BLE.


![TOTEM layout](/docs/images/TOTEM_layout.svg)



## HOW TO USE

Run the `qmk` setup if you haven't yet
> Before running this, make sure you already installed `dos2unix`
```
qmk setup
```
them, initialize
```
make init
```

## For WSL
1. You don't need to run `qmk setup`
2. Use: [ https://wsl.qmk.fm/guide ]
3. Because the tool can't leverage this makefile, you need to copy & paste the commands from the (makefile)[./makefile] in order to flash left/right keyboard

