cmake_minimum_required(VERSION 3.20)
project(FIPS_140)

set(CMAKE_CXX_STANDARD 17)

add_executable(FIPS_140 main.cpp
        FIPStest.cpp
        FIPStest.h)
