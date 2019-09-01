#ifndef __CUDACOMPRESS__HISTOGRAM_CPU_H__
#define __CUDACOMPRESS__HISTOGRAM_CPU_H__


#include <cudaCompress/global.h>


namespace cudaCompress {

void histogramCPU(uint* pHistogram, const ushort* pData, uint elemCount, uint binCount);

}


#endif
