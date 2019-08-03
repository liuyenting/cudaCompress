cmake_minimum_required(VERSION 3.10)

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
		# CUDA
		Encode.cpp
		Instance.cpp
		InstanceImpl.cpp
		profiler/profiler.cpp
		profiler/profilerlogwriter.cpp
		profiler/profilerstreamwriter.cpp
		reduce/reduce_plan.cpp
		scan/scan_plan.cpp
		Timing.cpp
		util/CudaTimer.cpp
		
		# CPU
		CPU/ArithmeticCPU.cpp
		CPU/EncodeCPU.cpp
		CPU/GolombRiceCPU.cpp
		CPU/HistogramCPU.cpp
		CPU/HuffmanCPU.cpp
		CPU/HuffmanTableCPU.cpp
		CPU/RBUCCPU.cpp
		CPU/RunLengthCPU.cpp
		CPU/YCoCgCPU.cpp
)

target_include_directories(
    cudaCompressLib
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}
        ${CMAKE_SOURCE_DIR}/src
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
		OUTPUT_NAME "cudacompress"
)

target_link_libraries(
    cudaCompressLib
    PRIVATE
		OpenMP::OpenMP_CXX
		${CUDART_LIBRARY}
)
