#ifndef CUDA_SYSTEMS_H
#define CUDA_SYSTEMS_H

#include"cudaSignals.h"

class Systems{
	public:
		Systems(void){};
        virtual bool activate(Signals &sig) = 0;
		virtual ~Systems(void){}; 
};


class FIRFilter: public Systems{
       public:
              FIRFilter(void){};
              bool activate(Signals &sig) { return true; }
              virtual ~FIRFilter(void){};	      
};

class IIRFilter: public Systems{
       public:
              IIRFilter(void){}
              bool activate(Signals &sig) { return true; }
              virtual ~IIRFilter(void){};
};



Signals & operator<<(Systems &sys,  Signals &sig);

#endif

