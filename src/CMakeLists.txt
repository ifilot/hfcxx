 #*************************************************************************
 #   CMakeLists.txt  --  This file is part of Netris.                     *
 #                                                                        *
 #   Copyright (C) 2016, Ivo Filot                                        *
 #                                                                        *
 #   Netris is free software: you can redistribute it and/or modify       *
 #   it under the terms of the GNU General Public License as published    *
 #   by the Free Software Foundation, either version 3 of the License,    *
 #   or (at your option) any later version.                               *
 #                                                                        *
 #   Netris is distributed in the hope that it will be useful,            *
 #   but WITHOUT ANY WARRANTY; without even the implied warranty          *
 #   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.              *
 #   See the GNU General Public License for more details.                 *
 #                                                                        *
 #   You should have received a copy of the GNU General Public License    *
 #   along with this program.  If not, see http://www.gnu.org/licenses/.  *
 #                                                                        *
 #*************************************************************************/

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

# Configure static build
SET(BUILD_SHARED_LIBRARIES OFF)

IF(WIN32)
SET(CMAKE_FIND_LIBRARY_PREFIXES "")
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".dll")
ELSE()
SET(CMAKE_FIND_LIBRARY_PREFIXES "lib")
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so" ".a")
ENDIF()

# # add OS specific
# if(APPLE)
#     add_definitions(-D_APPLE)
#     SET(BOOST_INCLUDEDIR "/opt/local/include")
#     SET(BOOST_LIBRARYDIR "/opt/local/lib")
# endif()
# if(UNIX)
#     add_definitions(-Wno-literal-suffix)
#     SET(BOOST_INCLUDEDIR "/usr/include")
#     SET(BOOST_LIBRARYDIR "/usr/lib/x86_64-linux-gnu")
# endif()

# set Boost
# set (Boost_NO_SYSTEM_PATHS ON)
# set (Boost_USE_MULTITHREADED ON)
# set (Boost_USE_STATIC_LIBS ON)
# set (Boost_USE_STATIC_RUNTIME OFF)
# set (BOOST_ALL_DYN_LINK OFF)

# Include libraries
# find_package(TCLAP REQUIRED)
# find_package(SUNDIALS REQUIRED)
# find_package(Boost COMPONENTS system filesystem regex REQUIRED)
# find_package(CPPUNIT REQUIRED) # for unit tests

# Set include folders
include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_BINARY_DIR}
                    ${Boost_INCLUDE_DIRS}
                    ${TCLAP_INCLUDE_DIR}
					${SUNDIALS_INCLUDE_DIR}
                    ${CPPUNIT_INCLUDE_DIR})

# Add sources
file(GLOB SOURCES "*.cpp")

# add tests
# enable_testing ()
# add_subdirectory("test")

# Set executable
add_executable(hfcxx ${SOURCES})

# Link libraries
target_link_libraries(hfcxx)

###
# Installing
##
install (TARGETS hfcxx DESTINATION bin)
