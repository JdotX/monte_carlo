#ifndef RNG_TIMER_HPP
#define RNG_TIMER_HPP

#include <random>
#include <chrono>
#include "DefTypes.h"
#include <iostream>
#include "RNG/BoxMullerRNG.hpp"

class RNG_Timer
{
public:
    /**
     * \brief Comparing the single-threads performance of different generators
     * 
     * A manually written generator is used to compare with the built-in method
     */
    void Compare(int num_samples);
};

void RNG_Timer::Compare(int num_samples)
{
    std::default_random_engine generator;
    std::normal_distribution<data_t> distribution(0,1);

    auto baseline_start = std::chrono::system_clock::now();
    data_t temp_base = 0;
    for (int i = 0; i < num_samples; ++i) 
    {
        temp_base = distribution(generator);
    }
    auto baseline_end = std::chrono::system_clock::now();

    BoxMullerRNG rng;
    auto boxmuller_start = std::chrono::system_clock::now();
    for (int j = 0; j < num_samples; ++j)
    {
        ;//temp_base = rng.Generate();
    }
    auto boxmuller_end = std::chrono::system_clock::now();
    auto baseline_duration = std::chrono::duration_cast<std::chrono::microseconds>(baseline_end - baseline_start);
    auto boxmuller_duration = std::chrono::duration_cast<std::chrono::microseconds>(boxmuller_end - boxmuller_start);

    std::cout << "Benchmark results: \n";
    std::cout << "Built-in: \t" << baseline_duration.count() << std::endl;
    std::cout << "BoxMuller: \t" << boxmuller_duration.count() << std::endl;
    return;
}


#endif // RNG_TIMER_HPP