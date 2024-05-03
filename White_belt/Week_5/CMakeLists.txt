cmake_minimum_required(VERSION 3.27)
project(Week_5)

set(CMAKE_CXX_STANDARD 17)

add_executable(Week_5 main.cpp)
configure_file(${CMAKE_SOURCE_DIR}/data.txt ${CMAKE_BINARY_DIR}/data.txt COPYONLY)
