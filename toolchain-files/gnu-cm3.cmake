set(CMAKE_SYSTEM_NAME Generic CACHE INTERNAL "system name")
set(CMAKE_SYSTEM_PROCESSOR arm CACHE INTERNAL "processor")

set(mcu_arch cortex-m3)

set(CMAKE_C_COMPILER arm-none-eabi-gcc CACHE INTERNAL "c compiler")
set(CMAKE_CXX_COMPILER arm-none-eabi-g++ CACHE INTERNAL "cxx compiler")
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc CACHE INTERNAL "asm compiler")

set(CMAKE_OBJCOPY arm-none-eabi-objcopy CACHE INTERNAL "objcopy")
set(CMAKE_OBJDUMP arm-none-eabi-objdump CACHE INTERNAL "objdump")
set(CMAKE_SIZE arm-none-eabi-size CACHE INTERNAL "size")

set(CMAKE_C_FLAGS "-mthumb -mcpu=${mcu_arch} -std=c99 -fno-builtin -fdata-sections -ffunction-sections" CACHE INTERNAL "c compiler flags")
set(CMAKE_CXX_FLAGS "-mthumb -mcpu=${mcu_arch} -fno-builtin -fdata-sections -ffunction-sections" CACHE INTERNAL "cxx compiler flags")
set(CMAKE_ASM_FLAGS "-mthumb -mcpu=${mcu_arch}" CACHE INTERNAL "asm compiler flags")

set(CMAKE_C_FLAGS_DEBUG "-O0 -g -g3 -ggdb" CACHE INTERNAL "c debug compiler flags")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -g3 -ggdb" CACHE INTERNAL "cxx debug compiler flags")
set(CMAKE_ASM_FLAGS_DEBUG "-g -g3 -ggdb" CACHE INTERNAL "asm debug compiler flags")

set(CMAKE_C_FLAGS_RELEASE "-Os" CACHE INTERNAL "c release compiler flags")
set(CMAKE_CXX_FLAGS_RELEASE "-Os" CACHE INTERNAL "cxx release compiler flags")
set(CMAKE_ASM_FLAGS_RELEASE "" CACHE INTERNAL "asm release compiler flags")

set(CMAKE_C_LINKER_WRAPPER_FLAG "-Wl," CACHE INTERNAL "")
set(CMAKE_CXX_LINKER_WRAPPER_FLAG "-Wl," CACHE INTERNAL "")
set(CMAKE_ASM_LINKER_WRAPPER_FLAG "-Wl," CACHE INTERNAL "")

set(CMAKE_C_LINKER_WRAPPER_FLAG_SEP "," CACHE INTERNAL "")
set(CMAKE_CXX_LINKER_WRAPPER_FLAG_SEP "," CACHE INTERNAL "")
set(CMAKE_ASM_LINKER_WRAPPER_FLAG_SEP "," CACHE INTERNAL "")

set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections -mthumb -mcpu=${mcu_arch}" CACHE INTERNAL "exe link flags")

set(CMAKE_C_COMPILER_WORKS ON)
set(CMAKE_CXX_COMPILER_WORKS ON)
