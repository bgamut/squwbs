/*
  ==============================================================================

    ForwardFFT.h
    Created: 7 Feb 2018 10:11:42am
    Author:  cumbe

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "math.h"
#define PI 3.14159265

//==============================================================================
/*
*/
class ForwardFFT    : public Component
{
public:
    ForwardFFT()
		: forwardFFT(fftOrder),
		fifoIndex(0),
		ready(false)
	{

		zeromem(fftData, sizeof(fftData));
		zeromem(fifo, sizeof(fifo));

    }

    ~ForwardFFT()
    {
    }
	enum{
	fftOrder = 4,
	fftSize = 1<<fftOrder 
	//equvalent to fftSize=2^4 (the above code uses the bit shifting function because it works in the enum bracket)
	//pow(2, fftOrder) 

	};
	float fifo[fftSize];
	float fifo00[fftOrder];

	void pushNextSampleIntoFifo(float sample) noexcept
	{

		if (fifoIndex < fftSize*2) {
		    fftData[fifoIndex] = sample;
		    ready = false;
		    fifoIndex=fifoIndex+1;
			max = 0.0;
			
	    }
		else if (fifoIndex > fftSize * 2) {
			forwardFFT.performFrequencyOnlyForwardTransform((fftData));
			for (int i = 0; i < fftSize; i++) {
				fifo[i] = fftData[i];
				for (int j = 1 << (fftOrder-1); j != 2; j / 2) {

				}
			}

			ready = true;
			fifoIndex = 0;
			max = 0.0;
		}
		else {
			forwardFFT.performFrequencyOnlyForwardTransform((fftData));
			for (int i = 0; i < fftSize; i++) {
				fifo[i] = fftData[i];
				for (int j = 1 << fftOrder; j == 1; j / 2) {

				}
	
			}

			ready = true;
			fifoIndex = 0;
			max = 0.0;
		}
		
		start = false;
    }

 
	void setReady(bool set) {
		ready = set;
	};
	bool getReady() {
		return ready;
	}

	bool ready;
	float fftData[2 * fftSize];
private:

    dsp::FFT forwardFFT;
    int fifoIndex;
	bool start=true;
	float max;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ForwardFFT)
};
