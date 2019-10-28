cmake_minimum_required(VERSION 3.8)
project(idk)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MyVec.h)
add_executable(idk ${SOURCE_FILES})