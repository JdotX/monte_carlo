#ifndef __BLACKSCHOLES_H_
#define __BLACKSCHOLES_H_

#include "Underlying.h"
#include "math.h"
#include <random>
#include <algorithm>

template <class RealType>
class BlackScholesSimulator
{
public:
    /**
     * \brief Cannot initialize without underlying instrument
     */
    BlackScholesSimulator() = delete;

    /**
     * \brief Cannot copy simulator from another copy
     */ 
    BlackScholesSimulator(const BlackScholesSimulator& bs2) = delete;

    /**
     * \brief Must be constructed with an underlying instrument
     */
    BlackScholesSimulator(const Underlying<RealType>& ins, const int num_rngs, const int num_sims) : 
        m_ins(ins), NUM_RNGS(num_rngs), NUM_SIMS(num_sims), distribution(0.0,1.0), distribution2(0.0,1.0), dis(0.0,1.0) {}

    /**
     * \brief Returns CDF of normal distribution
     */
    RealType NormalCDF(RealType value) {return 0.5*std::erfc(-value / std::sqrt(2));} // Is this 2 or 1/2?

    /** 
     * \brief Analytical price for vanilla European call option
     */
    RealType GetAnalyticalCallPrice()
    {
        return m_ins.S0 * NormalCDF(d1()) - m_ins.K * std::exp(m_ins.r * m_ins.T * (-1.0)) * NormalCDF(d2());  
    }

    /**
     * \brief Analytical price for vanilla European put option
     */
    RealType GetAnalyticalPutPrice()
    {
        return m_ins.K * std::exp(m_ins.r * m_ins.T * (-1.0)) * NormalCDF(d2() * (-1.0)) - m_ins.S0 * NormalCDF(d1() * (-1.0));
    }

    RealType GetSimulateCallPrice()
    {
        RealType S_adjust = m_ins.S0 * std::exp(m_ins.T*(m_ins.r-0.5*m_ins.v*m_ins.v));
        RealType S_cur = 0.0;
        RealType payoff = 0.0;

        for (int i=0; i<NUM_SIMS; ++i) 
        {
            RealType gauss_rn = distribution2(generator, dis);
            S_cur = S_adjust * std::exp(sqrt(m_ins.v * m_ins.v * m_ins.T) * gauss_rn);
            payoff += std::max((S_cur - m_ins.K), zero);
        }

        return (payoff / (1.0*NUM_SIMS)) * exp((-1.0) * m_ins.r * m_ins.T);
    }

    RealType GetSimulatePutPrice()
    {
        RealType S_adjust = m_ins.S0 * std::exp(m_ins.T*(m_ins.r - 0.5*m_ins.v*m_ins.v));
        RealType S_cur = 0.0;
        RealType payoff = 0.0;

        for (int i=0; i<NUM_SIMS; ++i) 
        {
            RealType gauss_rn = distribution2(generator, dis);
            S_cur = S_adjust * std::exp(sqrt(m_ins.v * m_ins.v * m_ins.T) * gauss_rn);
            payoff += std::max(m_ins.K - S_cur, zero);
        }

        return (payoff / (static_cast<RealType> (NUM_SIMS)) * exp((-1.0) * m_ins.r * m_ins.T));
    }

private:
    /**
     * \brief d1 in black-scholes formula
     */
    inline RealType d1() {return (std::log(m_ins.S0 / m_ins.K) + (m_ins.r + m_ins.v*m_ins.v / 2) * m_ins.T) / m_ins.v * std::sqrt(m_ins.T);}

    inline RealType d2() {return d1() - m_ins.v * std::sqrt(m_ins.T);} 

    std::default_random_engine generator;
    std::normal_distribution<RealType> distribution;
    BoxMullerDistribution<RealType> distribution2;
    std::uniform_real_distribution<RealType> dis; 

    Underlying<RealType> m_ins; //!< Underlying instrument
    const int NUM_RNGS;
    const int NUM_SIMS;
    const RealType zero = 0.0;
};

#endif // __BLACKSCHOLES_H_