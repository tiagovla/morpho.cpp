cmake_minimum_required(VERSION 3.10)

project(morpho)

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

# add_subdirectory("docs")
# add_subdirectory("dependencies/googletest")

file(GLOB SOURCES src/*.cpp)
add_executable(morpho ${SOURCES})

target_link_libraries(morpho PRIVATE Eigen)
add_library(Eigen INTERFACE)
target_include_directories(Eigen INTERFACE dependencies/eigen)


include_directories(include src)
# target_include_directories(morpho PUBLIC include)
# target_include_directories(morpho PRIVATE source)
