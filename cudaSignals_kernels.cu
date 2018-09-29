__global__ void SinWaveKernel(float *data, int size, 
		              float amp, float freq, float ip, float sr, float tt)
{

};
	
__global__ void CosWaveKernel(float *data, int size, 
		              float amp, float freq, float ip, float sr, float tt)
{

};



	
void cudaSinWave(float *data, int size, 
                   float amp, float freq, float ip, float sr, float tt)
{
      SinWaveKernel<<<1024, 1024>>>(data, size, amp, freq, ip, sr, tt);

};
	
void cudaCosWave(float *data, int size, 
                   float amp, float freq, float ip, float sr, float tt)
{
      CosWaveKernel<<<1024, 1024>>>(data, size, amp, freq, ip, sr, tt);
};
