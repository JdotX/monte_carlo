#ifndef __BLACKSCHOLES_H_
#define __BLACKSCHOLES_H_

#include "Underlying.h"

template <class RealType>
class BlackScholesSimulator
{
public:
    BlackScholesSimulator() = delete;

    BlackScholesSimulator(const BlackScholesSimulator& bs2) = delete;

    /**
     * \brief Must be constructed with an underlying instrument
     */
    BlackScholesSimulator(const Underlying& instrument);

    /**
     * \brief Do the main simulation for coding
     */
    void DoSimulation();

private:
    Underlying m_instrument;
    static const int NUM_RNGS;
    static const int NUM_SIMS;
    static const int NUM_SIMGROUPS;
    static const int NUM_STEPS;
};

#endif // __BLACKSCHOLES_H_