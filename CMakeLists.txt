cmake_minimum_required(VERSION 3.6)
project(Taller_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES
    Conjunto.hpp
    tests.cpp)

add_executable(Taller_2 ${SOURCE_FILES})
target_link_libraries(Taller_2 gtest gtest_main)