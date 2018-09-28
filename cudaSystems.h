#ifndef CUDA_SYSTEMS_H
#define CUDA_SYSTEMS_H

class Signals;

class Systems{
	public:
		Systems(void);
		virtual ~Systems(void); 
};


class FIR: public Systems{
       public:
              FIR(void);
              virtual ~FIR(void);	      
};



Signals & operator<<(Systems &sys,  Signals &sig);

#endif

