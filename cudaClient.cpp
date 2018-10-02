#include"cudaSaSL.h"
#include"cudaSignals.h"


int main(void)
{
      SaSL &Rs = SaSL::Instance();
      Signals *sp  = Rs.initiateSignal(SignalType::SIN);
      sp->Configure(100, 1, 0, 100);      
      sp->Generator();
      sp->Output();

      delete sp;

      return 0;
}


