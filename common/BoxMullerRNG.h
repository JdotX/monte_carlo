// Random number generator class

#ifndef BOXMULLER_RNG_H_
#define BOXMULLER_RNG_H_

#include "DefTypes.h"
// Used to generate a uniform random distribution
#include <random>
#include <cmath>
#include <limits>
/**
 * \brief Base class for random number generators
 * 
 * This is the base class for generating random numbers
 */
class BoxMullerRNG 
{
public:
	//BoxMullerRNG();
	data_t Generate() const;

private:
	const int m_mean = 0;
	const int m_sd = 1;
	const int m_n = 10000;
	static const data_t pi = 3.1415926535;
	static const data_t epsilon = std::numeric_limits<data_t>::min();
};

#endif //BOXMULLER_RNG_H_