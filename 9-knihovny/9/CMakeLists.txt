cmake_minimum_required(VERSION 3.5)

project(9 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(9 main.cpp knihovna.cpp)
