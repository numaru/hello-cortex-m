# Hello Cortex-M

This example project show how to compile C code for an ARM Cortex-M micro-controller and run it in Renode.

The targeted MCU is a `stm32f103rb`.

The projet use uart to `printf()` in the terminal. The `libc_nano` and `nosys_nano` standard libraries are used to achieve this.

# Getting started

## Development environment

* CMake (3.14.0)
* Manjaro Linux (18.0.2)
* Renode (1.9.0)
* GNU Arm Embedded Toolchain (8.3.0)
* VSCode (1.32.3) with the following extension:
  * C/C++ (0.22.1)
  * CMake (0.0.17)
  * LinkerScript (1.0.0)
  * ARM (0.3.0)

## I belong to the TUI gang

**Configure**

```bash
cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=toolchain-files/gnu-cm3.cmake -DCMAKE_BUILD_TYPE=Debug
```

**Build**

```bash
cmake --build build
```

**Run**

```bash
# Run this command in a terminal
cmake --build build --target renode

# This one in another
arm-none-eabi-gdb build/HelloWorld.elf -ex "target extended-remote :3333"
```

# Known issues

* The SysTick handler trigger breakpoints during debug and it makes it harder.
