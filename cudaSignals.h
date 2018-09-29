#ifndef CUDA_SIGNALS_H
#define CUDA_SIGNALS_H

class Signals{
	public:
		float m_sr, m_tt; 
		Signals(void);    
		Signals(float SamplingRate, float Timeinterval):m_sr{SamplingRate}, m_tt{Timeinterval}{};
		virtual bool Generator(void) = 0;
		virtual ~Signals(void);  
};


class SinWave: public Signals {
	private:
		float m_amp, m_freq, m_ip;
	public:
		SinWave(void){};
		SinWave(float Amp, float Frequency, float InitPhase,
				float SamplingRate, float Timeinterval):Signals(SamplingRate, Timeinterval),
		m_amp{Amp}, m_freq{Frequency}, m_ip{InitPhase} {};
		virtual bool Generator(void);
		virtual ~SinWave(void){};
};

class CosWave: public Signals {
	private:
		float m_amp, m_freq, m_ip;
	public:
		CosWave(void){};
		CosWave(float Amp, float Frequency, float InitPhase,
				float SamplingRate, float Timeinterval):Signals(SamplingRate, Timeinterval),
		m_amp{Amp}, m_freq{Frequency}, m_ip{InitPhase} {};

		virtual bool Generator(void);
		virtual ~CosWave(void){};
};


#endif

