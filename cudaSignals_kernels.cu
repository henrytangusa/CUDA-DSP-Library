#include "cuda.h"
#include"cuda_runtime.h"


__global__ void SinWaveKernel(float *data, int size, 
                float amp, float freq, float ip, int sr, float tt)
{

}
                              

__global__ void CosWaveKernel(float *data, int size, 
                float amp, float freq, float ip, int sr, float tt)
{

}
                              
void SinWaveKernel(float *data, int size, 
                   float amp, float freq, float ip, int sr, float tt)
{
        SinWaveKernel<<1024, BLOCK >> (data, size, amp, freq, ip, sr, tt);
        check_error(cudaPeekAtLastError());
}


void CosWaveKernel(float *data, int size, 
                   float amp, float freq, float ip, int sr, float tt)
{
        SinWaveKernel<<1024, BLOCK >> (data, size, amp, freq, ip, sr, tt);
        check_error(cudaPeekAtLastError());
}

