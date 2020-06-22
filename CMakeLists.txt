cmake_minimum_required (VERSION 2.8)

project(hustlic_cpp)

include_directories(hj/complex)
include_directories(hj/string)
include_directories(hj/composition)

set(src_files
    hj/complex/complex.cpp
    hj/complex/main.cpp
    hj/string/MyString.cpp
    hj/composition/Guns.cpp
    hj/composition/Ak47.cpp
    hj/composition/Ak47Impl.cpp
    hj/composition/Player.cpp)

add_executable(test_complex ${src_files})
