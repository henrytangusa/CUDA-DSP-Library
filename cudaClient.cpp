#include"cudaSaSL.h"


int main(void)
{
      SaSL &Rs = SaSL::Instance();
      Rs.initiateSignal(SaSL::SIN);

      return 0;
}


