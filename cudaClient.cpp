#include"cudaSaSL.h"
#include"cudaSignals.h"


int main(void)
{
      SaSL &Rs = SaSL::Instance();
      Signals *sp  = Rs.initiateSignal(SaSL::COS);
      
      sp->Generator();

      delete sp;

      return 0;
}


