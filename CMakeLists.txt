cmake_minimum_required(VERSION 3.16)
project(6502-emulator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(6502
    src/main.cpp
        src/memory.h
        src/memory.cpp
        src/processor.cpp
        src/processor.h
        src/Instructionset.h
)
