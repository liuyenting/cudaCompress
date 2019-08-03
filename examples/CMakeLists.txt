###
# Declare dependencies
###
find_library(CUDART_LIBRARY cudart ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES})

###
# Binary target
### 
add_executable(
	cudaCompressExample
        CompressHeightfield.cpp
        CompressImage.cpp
        CompressVolume.cpp
        examples.cpp
        GPUResources.cpp
        main.cpp
        simpleExample.cpp
        tools/rawfile.cpp
        tthread/tinythread.cpp
)

target_include_directories(
    cudaCompressExample
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}
        ${CMAKE_SOURCE_DIR}/examples
)

set_target_properties(
	cudaCompressExample
    PROPERTIES
        # rename
		OUTPUT_NAME "gpu_test"
)

target_link_libraries(
    cudaCompressExample
    PRIVATE
        ${CUDART_LIBRARY}
        cudaCompressLib
)
