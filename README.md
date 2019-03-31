# Hello Cortex-M

This example project show how to compile C code for an ARM Cortex-M micro-controller and run it in QEMU.

The targeted MCU is a `lm3s6965` since this Cortex-M3 micro-controller is natively supported by QEMU.

The projet use semihosting to `printf()` in the terminal. The `libc_nano` and `rdimon_nano` standard libraries are used to achieve this.

# Getting started

## Development environment

* CMake (3.14.0)
* Manjaro Linux (18.0.2)
* [A fork of QEMU (~4.0.0-rc1) to support semihosting](https://github.com/numaru/qemu/tree/hotfix/semihosting_arm_cm)
* GNU Arm Embedded Toolchain (8.3.0)
* VSCode (1.32.3) with the following extension:
  * C/C++ (0.22.1)
  * CMake (0.0.17)
  * CMake Tools (1.1.3)
  * LinkerScript (1.0.0)
  * ARM (0.3.0)

## I belong to the GUI gang

* **Build**: Press `F7`.
* **Run**: Press `ctrl+shift+B`
* **Debug**: Press `F5`.

## I belong to the TUI gang

**Configure**

```bash
cmake -S. -Bbuild -DCMAKE_TOOLCHAIN_FILE=toolchain-files/gnu-cm3.cmake
```

**Build**

```bash
cmake --build build
```

**Run**

```bash
cmake --build build --target qemu
```

**Debug**

```bash
# Run this command in a terminal
cmake --build build --target qemu-gdb

# This one in another
arm-none-eabi-gdb build/HelloWorld.elf -ex "target extended-remote :3333"
```

# Known issues

* The vscode integration of gdb (C/C++ 0.22.1) does not provide a way to answer a read on `stdin` through semihosting. Use the raw `arm-none-eabi-gdb` TUI instead.