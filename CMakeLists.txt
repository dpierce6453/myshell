cmake_minimum_required(VERSION 3.21)
project(myshell)

set(CMAKE_CXX_STANDARD 17)

add_executable(myshell main.cpp mystring.cpp mystring.h)

enable_testing()
add_subdirectory(myshelltests)