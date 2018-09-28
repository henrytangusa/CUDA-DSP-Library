#ifndef CUDA_SASL_H
#define CUDA_SASL_H


#include<memory>
#include<vector>


using namespace std;

class Signals;
class Systems;

class SaSL
{
private:
	vector<shared_ptr<Signals>> m_Signalset;
	vector<shared_ptr<Systems>> m_Systemset;

        Signals createSignal(void);
        Systems createSystem(void);

	SaSL(void);
	~SaSL(void);
public:
        static SaSL &Instance(void) {
	    static SaSL m_Instance;
	    return m_Instance;
        }

        // delete copy and move constructors and assign operators
        SaSL(SaSL const&) = delete;             // Copy construct
        SaSL(SaSL&&) = delete;                  // Move construct
        SaSL& operator=(SaSL const&) = delete;  // Copy assign
        SaSL& operator=(SaSL &&) = delete;      // Move assign  
};

#endif

