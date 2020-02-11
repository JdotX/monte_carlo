#ifndef UNDERLYING_H_
#define UNDERLYING_H_

#include "DefTypes.h"
#include <iostream>

template<class RealType>
class Underlying
{
public:
    RealType T; //!< Time to expiration
    RealType r; //!< Risk-free interest rate to time T
    RealType v; //!< volatility 
    RealType S0; //!< Current stock price
    RealType K; //!< Strike price of the option

    Underlying(RealType timeToMature, 
               RealType riskFreeRate, 
               RealType volatility,
               RealType initPrice,
               RealType strikePrice) : T(timeToMature), r(riskFreeRate), v(volatility), S0(initPrice), K(strikePrice) {}
    
    Underlying(const Underlying& other)
    {
        T = other.T;
        r = other.r;
        v = other.v;
        S0 = other.S0;
        K = other.K;
    }

    /**
     * \brief print the info of the underlying
     */
    template <typename T>
    friend std::ostream& operator<<(std::ostream& out, const Underlying<T>& underlying);
};

template<class RealType>
std::ostream& operator<<(std::ostream& out, const Underlying<RealType>& underlying)
{
    out << "Underlying (T, r, v, S0, K): ("
        << underlying.T << ", "
        << underlying.r << ", "
        << underlying.v << ", "
        << underlying.S0 << ", "
        << underlying.K << ")";
    return out;
}

#endif // UNDERLYING_H_