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
		Histogram.cu
		Huffman.cu
		HuffmanTable.cu
		Instance.cpp
		InstanceImpl.cpp
		PackInc.cu
		profiler/profiler.cpp
		profiler/profilerlogwriter.cpp
		profiler/profilerstreamwriter.cpp
		reduce/reduce_plan.cpp
		RunLength.cu
		scan/scan_plan.cpp
		Timing.cpp
		util/Bits.cu
		util/CudaTimer.cpp
		util/DWTFloat.cu
		util/DWTInt.cu
		util/Quantize.cu
		util/YCoCg.cu

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
	PUBLIC
		# anything links to this library will need to use c++11
        cxx_std_11
)

set_target_properties(
	cudaCompressLib
	PROPERTIES
		# rename
		OUTPUT_NAME "cudacompress"
)

target_link_libraries(
    cudaCompressLib
	PRIVATE
		OpenMP::OpenMP_CXX
		${CUDART_LIBRARY}
)

if(BUILD_SHARED_LIBS)
	target_compile_definitions(
		cudaCompressLib
		PUBLIC
			CUCOMP_BUILD_DLL
	)
else()
	target_compile_definitions(
		cudaCompressLib
		PUBLIC
			CUCOMP_BUILD_STANDALONE
	)
endif()