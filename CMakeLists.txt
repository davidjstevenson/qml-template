cmake_minimum_required(VERSION 3.2)
project(QmlTest CXX C)

include(CMake/base.cmake)

# a workaround to make MSVC build tree much nicer if (MSVC)
if (MSVC)
   set(BUILD_OUTPUT_DIR ${BUILD_OUTPUT_PATH}/${CMAKE_CFG_INTDIR})
else()
   set(BUILD_OUTPUT_DIR ${BUILD_OUTPUT_PATH})
endif()

# define the build artifacts location
set(EXECUTABLE_OUTPUT_PATH ${BUILD_OUTPUT_PATH})
set(LIBRARY_OUTPUT_PATH ${EXECUTABLE_OUTPUT_PATH})

# include basic cmake options
include(CMake/settings.cmake)

set(SUBDIRECTORIES
    src
)

foreach(DIR ${SUBDIRECTORIES})
   add_subdirectory(${DIR})
endforeach()
