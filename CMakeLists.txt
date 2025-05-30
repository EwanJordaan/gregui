cmake_minimum_required(VERSION 3.31)
project(gregui)

set(CMAKE_CXX_STANDARD 20)

add_executable(gregui gregui.h
        window.h
        window.cpp)
