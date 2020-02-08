#ifndef UNDERLYING_H_
#define UNDERLYING_H_

#include "DefTypes.h"

class Underlying
{
public:
    data_t m_timeT;
    data_t m_riskFreeRate;
    data_t m_volatility;
    data_t m_initPrice;
    data_t m_strikePrice;

    Underlying(data_t, data_t, data_t, data_t, data_t);

    Underlying(const Underlying&);

    /**
     * \brief print the info of the underlying
     */
    void operator<<(const Underlying&) const;
};

#endif // UNDERLYING_H_