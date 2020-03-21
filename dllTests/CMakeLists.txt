cmake_minimum_required(VERSION 3.16)
project(dllTests)

set(CMAKE_CXX_STANDARD 11)

add_executable(dllTests main.cpp dllTemplated.cpp dllTemplated.h)