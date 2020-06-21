cmake_minimum_required (VERSION 2.8)

project(hustlic_cpp)

include_directories(hj/complex)
include_directories(hj/string)

set(src_files
    hj/complex/complex.cpp
    hj/complex/main.cpp
    hj/string/MyString.cpp)

add_executable(test_complex ${src_files})
