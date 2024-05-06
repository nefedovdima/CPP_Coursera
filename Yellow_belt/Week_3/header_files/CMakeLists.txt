cmake_minimum_required(VERSION 3.28)
project(header_files)

set(CMAKE_CXX_STANDARD 17)

add_executable(header_files main.cpp
        test_runner.h
        synonyms.h
        tests.h)
configure_file(${CMAKE_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/input.txt COPYONLY)