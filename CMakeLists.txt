cmake_minimum_required(VERSION 3.13)

project(HelloWorld)

add_subdirectory(cmsis)

add_executable(HelloWorld
    src/main.c
)

target_link_libraries(HelloWorld
    PRIVATE
        Cmsis::Cmsis
)

target_link_options(HelloWorld
    PRIVATE
        LINKER:-Map=output.map
)

target_link_options(HelloWorld
    PRIVATE
        --specs=nano.specs
        --specs=rdimon.specs
)

set_target_properties(HelloWorld
    PROPERTIES
        SUFFIX ".elf"
)

add_custom_command(TARGET HelloWorld POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:HelloWorld>
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    USES_TERMINAL
)

add_custom_target(qemu
    qemu-system-arm
        -cpu cortex-m3
        -machine lm3s6965evb
        -nographic
        -monitor null
        -serial null
        -semihosting
        -kernel;$<TARGET_FILE:HelloWorld>
    DEPENDS HelloWorld
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Run the HelloWorld in qemu"
    USES_TERMINAL
)

add_custom_target(qemu-gdb
    qemu-system-arm
        -cpu cortex-m3
        -machine lm3s6965evb
        -nographic
        -semihosting
        -gdb tcp::3333
        -S
        -kernel;$<TARGET_FILE:HelloWorld>
    DEPENDS HelloWorld
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Run the HelloWorld in qemu and start gdb"
    USES_TERMINAL
)
