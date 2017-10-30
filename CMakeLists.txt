cmake_minimum_required(VERSION 3.0.2)
project(mdcrystal_test)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#Manually add sources
#set(SOURCES src/mdcrystal.cpp src/catom.cpp src

#add sources
file(GLOB SOURCES "src/*.cpp")

add_executable(testMDcrystal ${SOURCES})