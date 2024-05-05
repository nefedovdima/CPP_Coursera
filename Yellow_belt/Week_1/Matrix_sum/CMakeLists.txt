cmake_minimum_required(VERSION 3.27)
project(Matrix_sum)

set(CMAKE_CXX_STANDARD 17)

add_executable(Matrix_sum main.cpp)

configure_file(${CMAKE_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/input.txt COPYONLY)