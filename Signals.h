#ifndef SIGNALS_H
#define SIGNALS_H

class Signals{
	public:
		Signals(void);    
		virtual bool Generator(void) = 0;
		virtual ~Signals(void);  
};


class Noise: public Signals {
       public:
	       Noise(void);
	       virtual bool Generator(void);
	       ~Noise(void);
};


#endif

