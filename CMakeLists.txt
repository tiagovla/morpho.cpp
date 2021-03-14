# cmake version
cmake_minimum_required(VERSION 3.0)

# project name
project(morpho)

# flags
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# files

# include
include_directories(./include ./src)

# target
add_executable(morpho ./src/main.cpp ./src/geometry.cpp)

# external libs

# docs
add_subdirectory("docs")
