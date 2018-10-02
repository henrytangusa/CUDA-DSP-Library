#ifndef CUDA_SIGNALS_H
#define CUDA_SIGNALS_H


enum class SignalType {
     NSG = 0,
     SIN = 1,
     COS   = 2
};

class Signals{
	public:
		float m_sr;  // sample rate 
		Signals(void);    
		Signals(float SamplingRate):m_sr{SamplingRate}{};
                Signals(Signals const &s):m_sr(s.m_sr){
                }
                Signals(Signals &&s):m_sr(s.m_sr){
                }
                
                Signals &operator= (Signals const &s)
                {
                     m_sr = s.m_sr;
                     return *this;
                }

                Signals &operator= (Signals &&s)
                {
                     m_sr = s.m_sr;
                     return *this;
                }
		virtual bool Generator(void) = 0;
                virtual void Configure(float Amp, float Frequency, float InitPhase, float SamplingRate) = 0;
                virtual void Output(void) const = 0;
		virtual ~Signals(void);  
};


class SinCosWave: public Signals {
        public:
                bool configured {false};

                SignalType m_type;
                float *m_pdata {nullptr};
		float m_amp, m_freq, m_ip; 
		SinCosWave(SignalType vf):m_type{vf} {};
		SinCosWave(float Amp, float Frequency, float InitPhase,
				float SamplingRate):Signals(SamplingRate),
		m_amp{Amp}, m_freq{Frequency}, m_ip{InitPhase} {};
                virtual void Configure(float Amp, float Frequency, float InitPhase, float SamplingRate);
		virtual bool Generator(void);
                virtual void Output(void) const;
		virtual ~SinCosWave(void);
};


#endif

