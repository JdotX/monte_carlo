#ifndef BOXMULLER_DISTRIBUTION_H_
#define BOXMULLER_DISTRIBUTION_H_
#include "DefTypes.h"
#include <random>

/**
 * \class BoxMullerDistribution
 * \brief RNG with normal distribution via Box-Muller algorithm
 * 
 * Templated implementation used to meet with std::normal_distribution conventions.
 */
template<class RealType=double>
class BoxMullerDistribution
{
public:
    BoxMullerDistribution (RealType mean=0.0, RealType stddev=1.0)
    {
        m_mean = mean;
        m_stddev = stddev;
    }

    template <class URNG, class UDIS>
    RealType operator()(URNG& gen, UDIS& dis)
    {
        RealType u0, u1, z0, z1;
        u1 = 0.0;
        while (u1 < epsilon)
        {
            u0 = dis(gen);
            u1 = dis(gen);
        }
  	    z0 = sqrt(-2.0 * log(u0)) * cos(pi * u1);
	    z1 = sqrt(-2.0 * log(u0)) * sin(pi * u1);

        return z0 * m_stddev + m_mean;
    }

private:
    RealType m_mean;
    RealType m_stddev;
    static constexpr RealType pi = 3.1415926535;
	static constexpr RealType epsilon = std::numeric_limits<data_t>::min();
};
#endif // BOXMULLER_DISTRIBUTION_H_