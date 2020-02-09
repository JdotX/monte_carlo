#ifndef __RNGBENCHMARK_H_
#define __RNGBENCHMARK_H_

#include "BaseBenchmark.h"
#include "BoxMullerDistribution.hpp"
#include <iostream>


/**
 * \class RNGBenchmark
 * \brief This benchmark tests the performance of normal RNGs.
 * 
 * Compared schemes: 
 * 1. Built-in normal random number generator
 * 2. Self-developed random numer generator with Box-Muller Algorithm
 */
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
    int m_samples; //!< Number of samples generated from normal RNG
};

#endif //__RNGBENCHMARK_H_