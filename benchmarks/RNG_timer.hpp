#ifndef RNG_TIMER_HPP
#define RNG_TIMER_HPP

class RNG_Timer
{
public:
    /**
     * \brief Comparing the single-threads performance of different generators
     * 
     * A manually written generator is used to compare with the built-in method
     */
    void Compare(int num_samples);
};

void RNG_Timer::Compare()
{

}


#endif // RNG_TIMER_HPP