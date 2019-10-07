cmake_minimum_required(VERSION 3.15)
project(GammelBoy)

set(CMAKE_CXX_STANDARD 17)

add_executable(GammelBoy main.cpp src/common.h src/cpu.hpp src/memory.hpp)