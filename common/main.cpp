/**
 * \mainpage This is testing main page
 * 
 * \author Jiacheng Xia
 * 
 * This repo is to develop hands on experience with monte-carlo simulations
 * for option pricing. 
 */
#include <iostream>
#include <chrono>
#include <random>
#include "RNGBenchmark.h"

int main()
{
    RNGBenchmark normalBench(1000000);
    normalBench.run();
    return 0;
}