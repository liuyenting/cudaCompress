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
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(
	cudaCompressTest
    PROPERTIES
        # rename
		OUTPUT_NAME "cpu_test"
)

target_link_libraries(
    cudaCompressTest
    PRIVATE
        ${CUDART_LIBRARY}
        cudaCompressLib
        cudaCompressLib_fallback
)
