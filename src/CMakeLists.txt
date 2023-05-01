#/**************************************************************************
 #  CMakeLists.txt  --  This file is part of HFCXX.                      *
 #                                                                       *
 #  Copyright (C) 2012, Ivo Filot                                        *
 #                                                                       *
 #  HFCXX is free software:                                              *
 #  you can redistribute it and/or modify it under the terms of the      *
 #  GNU General Public License as published by the Free Software         *
 #  Foundation, either version 3 of the License, or (at your option)     *
 #  any later version.                                                   *
 #                                                                       *
 #  HFCXX is distributed in the hope that it will be useful,             *
 #  but WITHOUT ANY WARRANTY; without even the implied warranty          *
 #  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.              *
 #  See the GNU General Public License for more details.                 *
 #                                                                       *
 #  You should have received a copy of the GNU General Public License    *
 #  along with this program.  If not, see http://www.gnu.org/licenses/.  *
 #                                                                       *
#**************************************************************************/

# set minimum cmake requirements
cmake_minimum_required(VERSION 2.8)
project (hfcxx)

# add custom directory to look for .cmake files
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/modules )

# Enable release build
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Configure header file
configure_file("config.h.in" "config.h")

# Check for OpenMP
find_package(OpenMP)
if (OPENMP_FOUND)
    option(HAS_OPENMP "OpenMP enabled" ON)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

# find libcppunit for unit testing
find_package(CPPUNIT REQUIRED) # for unit tests

# Set include folders
include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_BINARY_DIR})

# Add sources
file(GLOB SOURCES "*.cpp")
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_library(hfcxxsources STATIC ${SOURCES})

# Set executable
add_executable(hfcxx ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

# Set C++17
add_definitions(-std=c++17 -march=native)

# Link libraries
target_link_libraries(hfcxx hfcxxsources)

if(NOT DISABLE_TEST)
    message("[USER] Performing unit tests")
    enable_testing ()
    add_subdirectory("test")
else()
    message("[USER] Testing routine disabled")
endif()

###
# Installing
##
install (TARGETS hfcxx DESTINATION bin)
