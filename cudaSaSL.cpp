#include<iostream>
#include"cudaSystems.h"
#include"cudaSignals.h"
#include"cudaSaSL.h"

SaSL::SaSL(void)
{
     cout <<"SaSL Instance created" << endl;	
};

Signals *SaSL::initiateSignal(SignalType sgt)
{
     switch (sgt) {
         case SIN:
            return new SinWave;
         case COS: 
            return new CosWave;
         default:
            return nullptr;  
    } 
};

Systems * SaSL::initiateSystem(SystemType syt)
{
       switch(syt) {
            case FIR:
                return new FIRFilter;
            case IIR:
                return new IIRFilter;
            default:
               return nullptr;
       } 
};

SaSL::~SaSL(void)
{
     cout << "SaSL Instace destory" << endl; 
};




