#include "BoxMullerRNG.h"

data_t BoxMullerRNG::Generate() const
{
    data_t u0, u1, z0, z1;

    while (u1<epsilon) 
    {
        u0 = rand() * (1.0 / RAND_MAX);
        u1 = rand() * (1.0 / RAND_MAX);
    }
	z0 = sqrt(-2.0 * log(u0)) * cos(pi * u1);
	z1 = sqrt(-2.0 * log(u0)) * sin(pi * u1);

    return z0 * m_sd + m_mean;
}