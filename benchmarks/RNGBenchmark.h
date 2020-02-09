#ifndef __RNGBENCHMARK_H_
#define __RNGBENCHMARK_H_

#include "BaseBenchmark.h"
#include "RNG/BoxMullerDistribution.hpp"
#include <iostream>

class RNGBenchmark : public BaseBenchmark
{
public:
    RNGBenchmark(int s = 10000)
        : m_samples(s)
    {}

    virtual void run();

    inline void SetSamples(int s) {m_samples = s;}

    inline int GetSamples() {return m_samples;}

    virtual ~RNGBenchmark() = default;

private:
    int m_samples;
};

#endif //__RNGBENCHMARK_H_