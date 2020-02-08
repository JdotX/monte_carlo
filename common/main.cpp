#include <iostream>
#include <chrono>
#include <random>
#include "RNG/BoxMullerDistribution.hpp"

int main()
{
    int num_samples = 1000000;
    std::default_random_engine generator;
    std::normal_distribution<data_t> distribution(0,1);

    auto baseline_start = std::chrono::system_clock::now();
    data_t temp_base = 0;
    for (int i = 0; i < num_samples; ++i) 
    {
        temp_base = distribution(generator);
        //std::cout << temp_base << " ";
    }
    std::cout << std::endl;
    auto baseline_end = std::chrono::system_clock::now();
    std::uniform_real_distribution<data_t> dis(0.0, 1.0);   

    BoxMullerDistribution<data_t> distribution2(0.0,1.0);
    auto boxmuller_start = std::chrono::system_clock::now();
    for (int j = 0; j < num_samples; ++j)
    {
        temp_base = distribution2(generator, dis);
    }
    std::cout << std::endl;
    auto boxmuller_end = std::chrono::system_clock::now();
    auto baseline_duration = std::chrono::duration_cast<std::chrono::microseconds>(baseline_end - baseline_start);
    auto boxmuller_duration = std::chrono::duration_cast<std::chrono::microseconds>(boxmuller_end - boxmuller_start);

    std::cout << "Benchmark results: \n";
    std::cout << "Built-in: \t" << baseline_duration.count() << std::endl;
    std::cout << "BoxMuller: \t" << boxmuller_duration.count() << std::endl;
    return 0;
}