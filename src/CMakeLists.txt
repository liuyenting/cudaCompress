cmake_minimum_required(VERSION 3.10)
project(
	cudaCompressLib
	LANGUAGES CXX CUDA
)

###
# Declare dependencies
###
find_package(OpenMP REQUIRED)
find_library(CUDART_LIBRARY cudart ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES})

###
# Library target
### 
add_library(
	cudaCompressLib
		Encode.cpp
		Instance.cpp
		InstanceImpl.cpp
		Timing.cpp
		profiler/profiler.cpp
		profiler/profilerlogwriter.cpp
		profiler/profilerstreamwriter.cpp
		reduce/reduce_plan.cpp
		scan/scan_plan.cpp
		util/CudaTimer.cpp
)

target_include_directories(
    cudaCompressLib
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(
    cudaCompressLib
    PRIVATE
        cxx_std_11
)

set_target_properties(
	cudaCompressLib
	PROPERTIES
		# built with -dc so member functions could be called by other libraries
		CUDA_SEPARABLE_COMPILATION ON
		# rename
		OUTPUT_NAME "libcudacompress"
)

target_link_libraries(
    cudaCompressLib
    PRIVATE
		OpenMP::OpenMP_CXX
		${CUDART_LIBRARY}
)
