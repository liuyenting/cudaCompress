cmake_minimum_required(VERSION 3.10)

###
# Declare dependencies
###
find_library(CUDART_LIBRARY cudart ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES})

###
# Binary target
### 
add_executable(
	cudaCompressTest
        EncoderTestSuite.cpp
        main.cpp
)

target_include_directories(
    cudaCompressTest
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/test
)

target_compile_features(
    cudaCompressTest
    PRIVATE
        cxx_std_11
)

set_target_properties(
	cudaCompressTest
	PROPERTIES
		OUTPUT_NAME "testsuite"
)

target_link_libraries(
    cudaCompressTest
    PUBLIC
        cudaCompressLib
    PRIVATE
		${CUDART_LIBRARY}
)
