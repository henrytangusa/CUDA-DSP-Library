#include "cudaSignals.h"
#include "cudaSignals_kernels.h"
#include  <driver_types.h>
#include  "cuda_runtime.h"
#include  <cuda.h>
#include  <iostream>


using namespace std;

Signals::Signals(void)
{
}

Signals::~Signals(void)
{

}


void SinCosWave::Output(void) const
{
     for ( int i = 0; i < m_sr * m_freq; i++) {
          cout << m_pdata[i] << endl;
     }
}


void SinCosWave::Configure(float Amp, float Frequency, float InitPhase, float SamplingRate)
{
     if(configured) return; 
     m_amp = Amp;
     m_freq = Frequency;
     m_ip = InitPhase;
     m_sr = SamplingRate;
     cudaMallocManaged(&m_pdata, (int)(m_sr * m_freq));
     configured = true;
     
}

bool SinCosWave::Generator(void) 
{
     if (!configured) return false;
     if (m_type == SignalType::SIN)
           SinWaveKernel(m_pdata, m_sr * m_freq, m_amp, m_freq, m_ip, m_sr);
     else 
           CosWaveKernel(m_pdata, m_sr * m_freq, m_amp, m_freq, m_ip, m_sr);
     cudaDeviceSynchronize();
     return true; 
}


SinCosWave::~SinCosWave(void)
{
     if( m_pdata != nullptr) 
       cudaFree(m_pdata);
}


