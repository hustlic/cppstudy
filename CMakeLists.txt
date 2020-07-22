cmake_minimum_required (VERSION 2.8)

project(test_cpp)

add_compile_options(-std=c++14)

include_directories(hj/complex)
include_directories(hj/string)
include_directories(hj/composition)
include_directories(hj/fraction)
include_directories(hj/include)
include_directories(hj/licthread)


set(src_files
    hj/complex/complex.cpp
    hj/complex/main.cpp
    hj/string/MyString.cpp
    hj/composition/Guns.cpp
    hj/composition/Ak47.cpp
    hj/composition/Ak47Impl.cpp
    hj/composition/Player.cpp
    hj/fraction/Fraction.cpp
    hj/licthread/LicThread.cpp
    hj/licthread/Message.cpp)

#LINK_DIRECTORIES(/usr/local/lib)

add_executable(test_cpp ${src_files})

target_link_libraries(${PROJECT_NAME} -lpthread)
