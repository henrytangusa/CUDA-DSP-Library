#ifndef CUDA_SIGNALS_KERNELS_H
#define CUDA_SIGNALS_KERNELS_H

bool SinWaveKernel(float *data, int size, 
                   float amp, float freq, float ip, int sr);

bool CosWaveKernel(float *data, int size, 
                   float amp, float freq, float ip, int sr);

#endif
