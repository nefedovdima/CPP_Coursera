cmake_minimum_required(VERSION 3.28)
project(Integer_types)

set(CMAKE_CXX_STANDARD 17)

add_executable(Integer_types main.cpp)

configure_file(${CMAKE_SOURCE_DIR}/average_temp.txt ${CMAKE_BINARY_DIR}/average_temp.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/blocs_mass.txt ${CMAKE_BINARY_DIR}/blocs_mass.txt COPYONLY)