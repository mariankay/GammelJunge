cmake_minimum_required(VERSION 3.15)
project(GammelJunge)

set(CMAKE_CXX_STANDARD 17)

add_executable(GammelJunge main.cpp src/common.h src/cpu.hpp src/memory.hpp)