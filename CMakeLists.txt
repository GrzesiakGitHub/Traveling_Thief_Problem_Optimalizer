cmake_minimum_required(VERSION 3.27)
project(ttd)

set(CMAKE_CXX_STANDARD 17)

add_executable(ttd main.cpp
        AProblem.cpp
        AProblem.h
        Item.h
        City.h
        Thief.h)
