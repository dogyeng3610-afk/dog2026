cmake_minimum_required(VERSION 3.10)
project(dog2026)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
include(ExternalProject)

add_subdirectory(c_example/part3)
add_subdirectory(c_example/part4/carSerial)
add_subdirectory(c_example/part4/myRandom)
add_subdirectory(c_example/part4/baseballGame)
add_subdirectory(c_example/part5/date)
add_subdirectory(c_example/part5/twoDouble)
add_subdirectory(c_example/part6/scoreProcess)
add_subdirectory(ds/stack/mystack1)
add_subdirectory(ds/stack/mystack2)
add_subdirectory(ds/stack/mystack3)
add_subdirectory(ds/stack/mystack4)
add_subdirectory(ds/queue/myqueue1)
add_subdirectory(ds/queue/myqueue2)
add_subdirectory(ds/queue/myqueue3)
add_subdirectory(network)

ExternalProject_Add(atmega128_project
	SOURCE_DIR ${CMAKE_SOURCE_DIR}/atmega128
	BINARY_DIR ${CMAKE_BINARY_DIR}/atmega128-build
	CMAKE_ARGS
		-DCMAKE_TOOLCHAIN_FILE=${CMAKE_SOURCE_DIR}/atmega128/avr-toolchain.cmake
		-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON
        INSTALL_COMMAND ""
)
