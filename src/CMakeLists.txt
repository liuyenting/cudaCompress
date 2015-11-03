cuda_add_library ( cudaCompress
	CPU/YCoCgCPU.cpp
	CPU/HuffmanCPU.cpp
	CPU/EncodeCPU.cpp
	CPU/ArithmeticCPU.cpp
	CPU/HuffmanTableCPU.cpp
	CPU/EncoderTestSuite.cpp
	CPU/tools/stb_image.c
	CPU/RBUCCPU.cpp
	CPU/GolombRiceCPU.cpp
	CPU/RunLengthCPU.cpp
	CPU/HistogramCPU.cpp
	cudaCompress/RunLength.cu
	cudaCompress/Huffman.cu
	cudaCompress/Timing.cpp
	cudaCompress/reduce/reduce_plan.cpp
	cudaCompress/Histogram.cu
	cudaCompress/HuffmanTable.cu
	cudaCompress/profiler/profilerstreamwriter.cpp
	cudaCompress/profiler/profilerlogwriter.cpp
	cudaCompress/profiler/profiler.cpp
	cudaCompress/InstanceImpl.cpp
	cudaCompress/PackInc.cu
	cudaCompress/Instance.cpp
	cudaCompress/scan/scan_plan.cpp
	cudaCompress/Encode.cpp
	cudaCompress/util/Bits.cu
	cudaCompress/util/DWTInt.cu
	cudaCompress/util/YCoCg.cu
	cudaCompress/util/Quantize.cu
	cudaCompress/util/CudaTimer.cpp
	cudaCompress/util/DWTFloat.cu
	)

cuda_add_executable ( cudaCompressTest
	CPU/main.cpp
	)

target_link_libraries ( cudaCompressTest cudaCompress)

# cuda_add_executable ( examples
# 	examples/main.cpp
# 	)
# 
# target_link_libraries ( examples cudaCompress)

if (BUILD_SHARED_LIBS)
	target_compile_definitions(cudaCompress PUBLIC CUCOMP_BUILD_DLL)
else()
	target_compile_definitions(cudaCompress PUBLIC CUCOMP_BUILD_STANDALONE)
	target_compile_definitions(cudaCompressTest PUBLIC CUCOMP_BUILD_STANDALONE)
#	target_compile_definitions(examples PUBLIC CUCOMP_BUILD_STANDALONE)
endif()
