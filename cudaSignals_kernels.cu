#include "cuda.h"
#include "math_constants.h"
#include"cuda_runtime.h"


__global__ void runSinWaveKernel(float *data, int size, 
                float amp, float freq, float ip, int sr)  // tt time interval is not needed

{
     unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
     if (x >= size)  return;
     float sampleInterval = sr / freq;   // Sample rate/signal freq
     data[x] = amp * sinf((2.0 * CUDART_PI_F * (float)x) / sampleInterval + ip);
}
                              

__global__ void runCosWaveKernel(float *data, int size, 
                float amp, float freq, float ip, int sr)
{
     unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
     if (x >= size)  return;
     float sampleInterval = sr / freq;   // Sample rate/signal freq
     data[x] = amp * sinf((2.0 * CUDART_PI_F * (float)x) / sampleInterval + ip);
}
                              
bool SinWaveKernel(float *data, int size, 
                   float amp, float freq, float ip, int sr)
{
        runSinWaveKernel<<<1024, BLOCK >>> (data, size, amp, freq, ip, sr);
        cudaDeviceSynchronize();
        return cudaPeekAtLastError() == cudaSuccess;
}


bool CosWaveKernel(float *data, int size, 
                   float amp, float freq, float ip, int sr, float tt)
{
        runCosWaveKernel<<<1024, BLOCK >>> (data, size, amp, freq, ip, sr);
        cudaDeviceSynchronize();
        return cudaPeekAtLastError() == cudaSuccess;
}

