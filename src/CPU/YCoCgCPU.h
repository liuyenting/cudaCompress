#ifndef __CUDACOMPRESS__YCOCG_CPU_H__
#define __CUDACOMPRESS__YCOCG_CPU_H__


#include <cudaCompress/global.h>


namespace cudaCompress {

void convertRGBToYCoCgCPU(byte* pTarget, const byte* pData, int pixelCount);
void convertYCoCgToRGBCPU(byte* pTarget, const byte* pData, int pixelCount);

}


#endif
