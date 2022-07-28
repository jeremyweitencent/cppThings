cmake_minimum_required(VERSION 3.21)
project(cppthings)

set(CMAKE_CXX_STANDARD 11)

# Root path
set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

include_directories(
        desgin_patterns/behavior
        desgin_patterns/creates
        desgin_patterns/struct
        )

file(GLOB_RECURSE SRC_DIR_LIST
        "vtable/*.cpp"
        "static/*.cpp"
        "string_test/*.cpp"
        "template/*.cpp"
        "bits/*.cpp"
        "algorithms/*.cpp"
        )

add_executable(cppthings
        main.cpp
        ${SRC_DIR_LIST}
)
