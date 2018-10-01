#ifndef CUDA_SIGNALS_H
#define CUDA_SIGNALS_H

class Signals{
	public:
		float m_sr, m_tt; 
		Signals(void);    
		Signals(float SamplingRate, float Timeinterval):m_sr{SamplingRate}, m_tt{Timeinterval}{};
                Signals(Signals const &s):m_sr(s.m_sr), m_tt(s.m_tt) {
                }
                Signals(Signals &&s):m_sr(s.m_sr), m_tt(s.m_tt) {
                }
                
                Signals &operator= (Signals const &s)
                {
                     m_sr = s.m_sr;
                     m_tt = s.m_tt;
                     return *this;
                }

                Signals &operator= (Signals &&s)
                {
                     m_sr = s.m_sr;
                     m_tt = s.m_tt;
                     return *this;
                }
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

