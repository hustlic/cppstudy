cmake_minimum_required (VERSION 2.8)

project(hustlic_cpp)

include_directories(hj/complex)

add_executable(test_complex hj/complex/complex.cpp hj/complex/main.cpp)