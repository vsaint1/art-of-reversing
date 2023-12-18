cmake_minimum_required(VERSION 3.15)

project(aor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE MEMORY "memory/*.cpp")
file(GLOB_RECURSE FEATURES "cheetos/*.cpp")
add_executable(${PROJECT_NAME} main.cpp ${MEMORY} ${FEATURES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.hpp)