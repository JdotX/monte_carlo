#include "BoxMullerRNG.hpp"
#include <cstdlib>
#include <iostream>

data_t BoxMullerRNG::Generate()
{
    data_t u0, u1, z0, z1;
	std::mt19937 gen(rd());
    u1 = 0.0;

    std::uniform_real_distribution<data_t> dis(0.0, 1.0);   

    while (u1<epsilon) 
    {
        u0 = dis(gen); //rand() * (1.0 / RAND_MAX);
        //std::cout << u0 << std::endl;
        u1 = dis(gen); //rand() * (1.0 / RAND_MAX);
    }
	z0 = sqrt(-2.0 * log(u0)) * cos(pi * u1);
	z1 = sqrt(-2.0 * log(u0)) * sin(pi * u1);

    return z0 * m_sd + m_mean;
}