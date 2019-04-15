cmake_minimum_required(VERSION 3.13)
project(elf-inspector)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE src "src/**.h" "src/**.cpp")
add_executable(elf-inspector ${src})