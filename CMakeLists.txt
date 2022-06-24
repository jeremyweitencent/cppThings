cmake_minimum_required(VERSION 3.21)
project(cppthings)

set(CMAKE_CXX_STANDARD 11)

add_executable(cppthings main.cpp
        vtable/vtable_main.cpp
        static/static_main.cpp
        string_test/string_main.cpp)
#        static/static_main.h)
