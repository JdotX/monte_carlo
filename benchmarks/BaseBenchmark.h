#ifndef __BASEBENCHMARK_H_
#define __BASEBENCHMARK_H_

/**
 * \class BaseBenchmark
 * \brief This is the abstract base class for all benchmarking
 */
class BaseBenchmark
{
public:
    virtual void run() = 0;

    virtual ~BaseBenchmark() = default;
};

#endif //__BASEBENCHMARK_H_