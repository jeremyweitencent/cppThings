cmake_minimum_required(VERSION 3.21)
project(cppthings)

set(CMAKE_CXX_STANDARD 11)

# Root path
set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

include_directories(${CMAKE_CURRENT_LIST_DIR}/desgin_patterns)

add_executable(cppthings main.cpp
        vtable/vtable_main.cpp
        static/static_main.cpp
        string_test/string_main.cpp
        template/template_hpp.h
        marco/marco_hpp.h
        template/template_cpp.cpp)
#        static/static_main.h)
