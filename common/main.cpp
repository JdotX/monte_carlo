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