cmake_minimum_required(VERSION 3.10)
project(queue1)

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_executable(queue1 main.c queue1.c)

