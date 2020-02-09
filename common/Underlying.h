#ifndef UNDERLYING_H_
#define UNDERLYING_H_

#include "DefTypes.h"
#include <iostream>

template<class RealType>
class Underlying
{
public:
    RealType m_timeToMature;
    RealType m_riskFreeRate;
    RealType m_volatility;
    RealType m_initPrice;
    RealType m_strikePrice;

    Underlying(RealType timeToMature, 
               RealType riskFreeRate, 
               RealType volatility,
               RealType initPrice,
               RealType strikePrice) : m_timeToMature(timeToMature), m_riskFreeRate(riskFreeRate), m_volatility(volatility), m_initPrice(initPrice), m_strikePrice(strikePrice);
    
    Underlying(const Underlying& other)
    {
        m_timeToMature = other.m_timeToMature;
        m_riskFreeRate = other.m_riskFreeRate;
        m_volatility = other.m_volatility;
        m_initPrice = other.m_initPrice;
        m_strikePrice = other.m_strikePrice;
    }

    /**
     * \brief print the info of the underlying
     */
    friend std::ostream& operator<<(std::ostream& out, const Underlying& underlying) const;
};

template<class RealType>
std::ostream& operator<<(std::ostream& out, const Underlying<RealType>& underlying)
{
    out << "Underlying (t, r, v, s0, K): ("
        << underlying.m_timeToMature << ","
        << underlying.m_riskFreeRate << ","
        << underlying.m_volatility << ","
        << underlying.m_initPrice << ","
        << underlying.m_strikePrice << ")";
}

#endif // UNDERLYING_H_