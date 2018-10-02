#ifndef CUDA_SIGNALS_KERNELS_H
#define CUDA_SIGNALS_KERNELS_H

extern "C" bool SinWaveKernel(float *data, int size, 
                   float amp, float freq, float ip, int sr);

extern "C" bool CosWaveKernel(float *data, int size, 
                   float amp, float freq, float ip, int sr);

#endif
