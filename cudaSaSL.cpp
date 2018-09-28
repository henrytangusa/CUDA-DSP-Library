#include<iostream>
#include"cudaSystems.h"
#include"cudaSignals.h"
#include"cudaSaSL.h"

SaSL::SaSL(void)
{
     cout <<"SaSL Instance created" << endl;	
};

shared_ptr<Signals> SaSL::initiateSignal(SignalType sgt)
{
     switch (sgt) {
         case SIN:
         {
            shared_ptr<SinWave> ssp (new SinWave);
            return ssp;
         }
         break;
         default:
            return nullptr;  
    } 
};

shared_ptr<Systems> SaSL::initiateSystem(SystemType syt)
{
       switch(syt) {
            case FIR:
            {
                shared_ptr<FIRFilter> fir( new FIRFilter);
                return fir;
            }
            break;
            case IIR:
            {
                shared_ptr<IIRFilter> iir( new IIRFilter);
                return iir;
            }
            break;
            default:
               return nullptr;
       } 
};

SaSL::~SaSL(void)
{
     cout << "SaSL Instace destory" << endl; 
};




