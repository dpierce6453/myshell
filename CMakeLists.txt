cmake_minimum_required(VERSION 3.21)
project(myshell)

set(CMAKE_CXX_STANDARD 17)

add_executable(myshell main.cpp mystring.cpp mystring.h historybuffer.cpp historybuffer.h processors/cmdprocessor.cpp processors/cmdprocessor.h processors/historyprocessor.cpp processors/historyprocessor.h processors/processorfactory.cpp processors/processorfactory.h processors/byebyeprocessor.cpp processors/byebyeprocessor.h)

enable_testing()
add_subdirectory(myshelltests)