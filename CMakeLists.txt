# cmake version
cmake_minimum_required(VERSION 3.16)

# project name
project(morpho)

# flags
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)


# files
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
add_subdirectory("docs")

# include
include_directories(include src ${Boost_INCLUDE_DIRS})

# target
file(GLOB SOURCES src/*.cpp)
add_executable(morpho ${SOURCES})

# external libs
target_link_libraries(morpho Eigen3::Eigen ${Boost_LIBRARIES})
