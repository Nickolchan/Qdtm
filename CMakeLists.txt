cmake_minimum_required(VERSION 3.6)
project(Qdtm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Task.cpp Task.h)
add_executable(Qdtm ${SOURCE_FILES})