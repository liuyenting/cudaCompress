#include <cudaCompress/Timing.h>

#include "cudaUtil.h"
#include "util.h"

#include "InstanceImpl.h"


namespace cudaCompress {

void setTimingDetail(Instance* pInstance, ETimingDetail detail)
{
    pInstance->setTimingDetail(detail);
}

void getTimings(Instance* pInstance, std::vector<std::string>& names, std::vector<float>& times)
{
    pInstance->getTimings(names, times);
}

void printTimings(Instance* pInstance)
{
    pInstance->printTimings();
}

void resetTimings(Instance* pInstance)
{
    pInstance->resetTimings();
}

}
