cmake_minimum_required(VERSION 3.10)
project(
	cudaCompressLib
	LANGUAGES CUDA CXX
)

target_include_directories(
    cudaCompress
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(
	cudaCompress
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

target_compile_features(
    cudaCompress
    PRIVATE
        cxx_std_11
)

find_package(OpenMP REQUIRED)
target_link_libraries(
    cudaCompress
    PRIVATE
        OpenMP::OpenMP_CXX
)
