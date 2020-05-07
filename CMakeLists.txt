cmake_minimum_required(VERSION 3.13)

project(HelloWorld)

set(HAL_STM32_MCU stm32f103xb)

add_subdirectory(hal-stm32)

add_executable(HelloWorld
    src/main.c
    src/retarget.c
)

target_link_libraries(HelloWorld
    PRIVATE
        HalStm32::HalStm32
)

target_link_options(HelloWorld
    PRIVATE
        LINKER:-Map=output.map
)

target_link_options(HelloWorld
    PRIVATE
        --specs=nano.specs
        --specs=nosys.specs
)

set_target_properties(HelloWorld
    PROPERTIES
        SUFFIX ".elf"
)

add_custom_command(TARGET HelloWorld POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:HelloWorld>
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Print the size of HelloWorld"
    USES_TERMINAL
)

add_custom_target(renode
    renode
        -e "$$bin=@$<TARGET_FILE_NAME:HelloWorld>"
        -e "include @scripts/single-node/stm32f103.resc"
        -e "machine StartGdbServer 3333"
    DEPENDS HelloWorld
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Run the HelloWorld in renode and start a gdb server on ::3333"
    USES_TERMINAL
)
