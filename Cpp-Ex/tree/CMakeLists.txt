cmake_minimum_required(VERSION 3.5)
project(tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp exptree.h testexprtree.cpp exprtree.cpp logitree.h logitree.cpp)
add_executable(tree ${SOURCE_FILES})