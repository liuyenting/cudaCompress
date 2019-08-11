###
# Declare dependencies
###
find_package(OpenMP REQUIRED)

###
# Library target
### 
add_library(
	cudaCompressLib_fallback
		ArithmeticCPU.cpp
		EncodeCPU.cpp
		GolombRiceCPU.cpp
		HistogramCPU.cpp
		HuffmanCPU.cpp
		HuffmanTableCPU.cpp
		RBUCCPU.cpp
		RunLengthCPU.cpp
		YCoCgCPU.cpp
)

target_include_directories(
    cudaCompressLib_fallback
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}
		${CMAKE_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(
    cudaCompressLib_fallback
	PUBLIC
		# anything links to this library will need to use c++11
        cxx_std_11
)

set_target_properties(
	cudaCompressLib_fallback
	PROPERTIES
		# rename
		OUTPUT_NAME "cudacompress_fallback"
)

target_link_libraries(
    cudaCompressLib_fallback
	PRIVATE
		OpenMP::OpenMP_CXX
)

if(BUILD_SHARED_LIBS)
	target_compile_definitions(
		cudaCompressLib_fallback
		PUBLIC
			CUCOMP_BUILD_DLL
	)
else()
	target_compile_definitions(
		cudaCompressLib_fallback
		PUBLIC
			CUCOMP_BUILD_STANDALONE
	)
endif()