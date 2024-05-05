cmake_minimum_required(VERSION 3.28)
project(Tuples_and_pairs)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tuples_and_pairs main.cpp)
configure_file(${CMAKE_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/input.txt COPYONLY)
