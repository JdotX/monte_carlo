/**
 * \mainpage This is testing main page
 * 
 * \author Jiacheng Xia
 * 
 * This repo is to develop hands on experience with monte-carlo simulations
 * for option pricing. This repo consists of: 
 * 1. A random number generator from normal distribution with Box-Muller algorithm
 * 2. A simulator for pricing European options with Monte-Carlo methods
 * 3. Benchmarks for relevant variance-reduction techniques.
 */
#include <iostream>
#include <chrono>
#include <random>
#include "RNGBenchmark.h"
#include "BlackScholes.h"
#include "Underlying.h"

int main()
{
    Underlying<data_t> testStock(1, 0.05, 0.2, 100, 100);
    std::cout << testStock << std::endl;
    BlackScholesSimulator<data_t> bs_sim(testStock, 1, 10000000);
    std::cout << "Analytical call option price: " << bs_sim.GetAnalyticalCallPrice() << std::endl;
    std::cout << "Analytical put option price: " << bs_sim.GetAnalyticalPutPrice() << std::endl;

    std::cout << "Monte-carlo simulated call option price: " << bs_sim.GetSimulateCallPrice() << std::endl;
    std::cout << "Monte-carlo simulated put option price: " << bs_sim.GetSimulatePutPrice() << std::endl;

    //RNGBenchmark normalBench(1000000);
    //normalBench.run();
    return 0;
}