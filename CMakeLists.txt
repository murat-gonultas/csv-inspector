cmake_minimum_required(VERSION 3.20)
project(csv_inspector C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(ENABLE_WARNINGS "Enable strict warnings" ON)

if (ENABLE_WARNINGS)
    if (MSVC)
        add_compile_options(/W4 /WX)
    else()
        add_compile_options(-Wall -Wextra -Wpedantic -Werror)
    endif()
endif()

add_library(core
    src/core.c
)

target_include_directories(core PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(csv_inspector
    src/main.c
)

target_link_libraries(csv_inspector PRIVATE core)

enable_testing()

add_executable(tests_runner
    tests/test_runner.c
    tests/test_core.c
)

target_link_libraries(tests_runner PRIVATE core)

add_test(NAME unit_tests COMMAND tests_runner)