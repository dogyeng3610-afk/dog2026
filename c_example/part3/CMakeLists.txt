cmake_minimum_required(VERSION 3.10)
project(dog2026)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

file(GLOB EXECUTABLES "${CMAKE_CURRENT_LIST_DIR}/*.c")
# shell명령어 cmake 문법
# 파일(정보함수 변수명 "패턴-.c와 일치하면")

foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)  # .C를 빼고 EXE_NAME에
    add_executable(${EXE_NAME} ${EXECUTABLE})
endforeach()

# CMAKELISTS.txt 다시 저장