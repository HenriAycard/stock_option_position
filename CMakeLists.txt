cmake_minimum_required(VERSION 3.8)
project(Portfolio)

set(CMAKE_CXX_STANDARD 11)


find_package(Python3 COMPONENTS Interpreter Development)
if (PYTHONLIBS_FOUND)
    include_directories(${PYTHON_INCLUDE_DIRS})
    message("Using default python version: " ${PYTHONLIBS_VERSION_STRING})
endif()


add_subdirectory(lib/pybind11)
include_directories(SYSTEM lib/pybind11/include)

file(GLOB_RECURSE SOURCES src/**.cpp)
add_library(cpp_library SHARED ${SOURCES})
target_include_directories(cpp_library PUBLIC ./include)

add_subdirectory(cpp_library_position)