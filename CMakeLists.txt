cmake_minimum_required(VERSION 3.13)
project(Register_Machine)

set(CMAKE_CXX_STANDARD 14)

add_executable(Register_Machine main.cpp Machine.cpp Machine.h Program.cpp Program.h Instruction.cpp Instruction.h)