cmake_minimum_required(VERSION 3.17)
project(TestLogger1)

set(CMAKE_CXX_STANDARD 11)

add_executable(TestLogger1
        main.cpp
        Logger.cpp
        Logger.h)