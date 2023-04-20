cmake_minimum_required(VERSION 3.26)
project(brianfuck_interpreter C)

set(CMAKE_C_STANDARD 23)

add_executable(brianfuck_interpreter brainfuck.c)
