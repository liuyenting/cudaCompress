cmake_minimum_required(VERSION 2.8)
find_package(CUDA QUIET REQUIRED)

# We want c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Pass options to NVCC
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-O3 -std=c++11 -gencode arch=compute_30,code=sm_30)

# Specify include directories
include_directories(
	include
	src
	)

add_subdirectory( src )
