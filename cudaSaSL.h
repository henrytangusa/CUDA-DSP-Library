#ifndef CUDA_SASL_H
#define CUDA_SASL_H

#include "cudaSignals.h"

#include<memory>
#include<vector>


using namespace std;

class Systems;

class SaSL
{
    public:

        enum SystemType {
            FIR = 0,
            IIR = 1
        };

        static SaSL &Instance(void) {
            static SaSL m_Instance;
            return m_Instance;
        }

        // delete copy and move constructors and assign operators
        SaSL(SaSL const&) = delete;             // Copy construct
        SaSL(SaSL&&) = delete;                  // Move construct
        SaSL& operator=(SaSL const&) = delete;  // Copy assign
        SaSL& operator=(SaSL &&) = delete;      // Move assign  


        Signals * initiateSignal(SignalType sgt);
        Systems * initiateSystem(SystemType syt);

    private:
        SaSL(void);
        ~SaSL(void);

};

#endif

