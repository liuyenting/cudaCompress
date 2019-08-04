cmake_minimum_required(VERSION 3.10)
project(
    cudaCompress
    LANGUAGES CXX CUDA
)

option(BUILD_SHARED_LIBS "Build shared library" ON)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)
