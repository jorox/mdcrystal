#the cmake file here follows the tutorial https://cmake.org/cmake-tutorial/
cmake_minimum_required (VERSION 3.0.2)
project (mdcrystal)

# The version number
set (mdcrystal_VERSION_MAJOR 0)
set (mdcrystal_VERSION_MINOR 1)
set (mdcrystal_VERSION_PATCH 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/mdcrystalConfig.h.in"
  "${PROJECT_BINARY_DIR}/mdcrystalConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the tinyxml2 library
include_directories ("${PROJECT_SOURCE_DIR}/packages/tinyxml2")
add_subdirectory (packages/tinyxml2)
set (EXTRA_LIBS ${EXTRA_LIBS} tinyxml2)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#Manually add sources
#set(SOURCES src/mdcrystal.cpp src/catom.cpp src

#add sources
file(GLOB SOURCES "src/*.cpp")
add_executable(mdcrystal ${SOURCES})
target_link_libraries (mdcrystal ${EXTRA_LIBS})

# ADD THE INSTALL TARGETS
install (TARGETS mdcrystal DESTINATION bin)
install (FILES "${PROJECT_SOURCE_DIR}/mdcrystalConfig.h"
  DESTINATION include)