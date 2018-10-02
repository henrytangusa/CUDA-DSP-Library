#include "cudaSignals.h"
#include "cudaSignals_kernels.h"
#include  <cudnn.h>
#include  <driver_types.h>
#include  <iostream>


using namespace std;

Signals::Signals(void)
{
}

Signals::~Signals(void)
{

}


bool SinWave::Generator(void) 
{
     float *pData;
     float samplerate = 100;
     float frequence = 1;
     int size = samplerate * frequence;
     cudaMallocManaged(&pData, size);
     SinWaveKernel(pData, size, 10.0, frequence, 0, samplerate);
     cudaDeviceSynchronize();
     for ( int i = 0; i< size; i++)
         cout << pData[i] << endl;;
     cudaFree(pData);
     return true; 
}


bool CosWave::Generator(void) 
{
     float *pData;
     float samplerate = 100;
     float frequence = 1;
     int size = samplerate * frequence;
     cudaMallocManaged(&pData, size);
     CosWaveKernel(pData, size, 10.0, frequence, 0, samplerate);
     cudaDeviceSynchronize();
     for ( int i = 0; i< size; i++)
         cout << pData[i] << endl;;
     cudaFree(pData);
     return true; 
}




