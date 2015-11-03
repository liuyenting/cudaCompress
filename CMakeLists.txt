cmake_minimum_required(VERSION 2.8)
find_package(CUDA QUIET REQUIRED)

# We want c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# CMake < 3.1 does not support above variables
if (CMAKE_VERSION VERSION_LESS "3.1")
	if ((CMAKE_CXX_COMPILER_ID MATCHES "Clang") OR (CMAKE_CXX_COMPILER_ID STREQUAL "GNU"))
		set(CMAKE_CXX_FLAGS "-std=c++11")
	else()
		message(FATAL_ERROR "Cannot enable c++11, don't know how for this compilers use CMake > 3.1 or update CMakeLists.txt for your compiler.")
	endif()

endif()

# Pass options to NVCC
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-O3 -std=c++11 -gencode arch=compute_30,code=sm_30)

# Specify include directories
include_directories(
	include
	src
	)

add_subdirectory( src )
