cmake_minimum_required(VERSION 3.13)

project(Cmsis LANGUAGES C ASM)

add_library(CmsisWeak
    system_lm3s.c
    $<$<STREQUAL:${CMAKE_C_COMPILER_ID},GNU>:GNU/startup_lm3s6965.s>
)

target_link_options(CmsisWeak
    INTERFACE
        $<$<STREQUAL:${CMAKE_C_COMPILER_ID},GNU>:-T ${CMAKE_CURRENT_SOURCE_DIR}/GNU/lm3s6965.ld>
)

target_include_directories(CmsisWeak
    PUBLIC
        .
        Include
)

add_library(Cmsis INTERFACE)

target_link_libraries(Cmsis
    INTERFACE
        $<$<STREQUAL:${CMAKE_C_COMPILER_ID},GNU>:-Wl,-whole-archive>
            CmsisWeak
        $<$<STREQUAL:${CMAKE_C_COMPILER_ID},GNU>:-Wl,-no-whole-archive>
)

add_library(Cmsis::Cmsis ALIAS Cmsis)
