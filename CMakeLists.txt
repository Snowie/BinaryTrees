cmake_minimum_required(VERSION 2.8.4)
project(Binary_Search_Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp bst.cpp)
add_executable(Binary_Search_Tree ${SOURCE_FILES})