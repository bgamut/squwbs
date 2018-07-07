/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
*/
double toDB (double inputValue){
    //return 20.0 * ((inputValue) > 0.00001 ? log10f(inputValue) : -6.3);
    //return 20.0*log10f(inputValue);
    return log(inputValue)/log(powf(2.0, 1/6));
}
double toLinear(double dB){
    //return powf(10.0, dB);
    return powf(powf(2.0,1/6),(dB-6.0));
}
class LP6 {
public:
  LP6() :
  cutoff(0.1),
  resonance(0.0),
  buf0(0.0)
  {
    calculateFeedbackAmount();
  };
  double process(double inputValue);
  inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
  inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
  inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
  double cutoff;
  double resonance;
  double feedbackAmount;
  
  double buf0;
};
class LP12 {
public:
    LP12() :
    cutoff(0.1),
    resonance(0.0),
    buf0(0.0),
    buf1(0.0)
    {
        calculateFeedbackAmount();
    };
    double process(double inputValue);
    inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
    inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
    inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
    double cutoff;
    double resonance;
    double feedbackAmount;
    
    double buf0;
    double buf1;
};
class LP24 {
public:
    LP24() :
    cutoff(0.1),
    resonance(0.0),
    buf0(0.0),
    buf1(0.0),
	buf2(0.0),
    buf3(0.0)
    {
        calculateFeedbackAmount();
    };
    double process(double inputValue);
    inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
    inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
    inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
    double cutoff;
    double resonance;
    double feedbackAmount;
    
    double buf0;
    double buf1;
	double buf2;
	double buf3;
};
class LP36 {
public:
  LP36() :
  cutoff(0.1),
  resonance(0.0),
  buf0(0.0),
  buf1(0.0),
  buf2(0.0),
  buf3(0.0),
  buf4(0.0),
  buf5(0.0)
  {
    calculateFeedbackAmount();
  };
  double process(double inputValue);
  inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
  inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
  inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
  double cutoff;
  double resonance;
  double feedbackAmount;
  double buf0;
  double buf1;
  double buf2;
  double buf3;
  double buf4;
  double buf5;
};
class LP48 {
public:
  LP48() :
  cutoff(0.1),
  resonance(0.0),
  buf0(0.0),
  buf1(0.0),
  buf2(0.0),
  buf3(0.0),
  buf4(0.0),
  buf5(0.0),
  buf6(0.0),
  buf7(0.0)
  {
    calculateFeedbackAmount();
  };
  double process(double inputValue);
  inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
  inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
  inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
  double cutoff;
  double resonance;
  double feedbackAmount;
  double buf0;
  double buf1;
  double buf2;
  double buf3;
  double buf4;
  double buf5;
  double buf6;
  double buf7;
};
class HP12 {
public:
    HP12() :
    cutoff(0.1),
    resonance(0.0),
    buf0(0.0),
    buf1(0.0)
    {
        calculateFeedbackAmount();
    };
    double process(double inputValue);
    inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
    inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
    inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
    double cutoff;
    double resonance;
    double feedbackAmount;
    double buf0;
    double buf1;
};
class HP24 {
public:
    HP24() :
    cutoff(0.1),
    resonance(0.0),
    buf0(0.0),
    buf1(0.0),
	buf2(0.0),
    buf3(0.0)
    {
        calculateFeedbackAmount();
    };
    double process(double inputValue);
    inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
    inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
    inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
    double cutoff;
    double resonance;
    double feedbackAmount;
    double buf0;
    double buf1;
	double buf2;
	double buf3;
};
class HP36 {
public:
  HP36() :
  cutoff(0.1),
  resonance(0.0),
  buf0(0.0),
  buf1(0.0),
  buf2(0.0),
  buf3(0.0),
  buf4(0.0),
  buf5(0.0)
  {
    calculateFeedbackAmount();
  };
  double process(double inputValue);
  inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
  inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
  inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
  double cutoff;
  double resonance;
  double feedbackAmount;
  double buf0;
  double buf1;
  double buf2;
  double buf3;
  double buf4;
  double buf5;

};
class HP48 {
public:
  HP48() :
  cutoff(0.1),
  resonance(0.0),
  buf0(0.0),
  buf1(0.0),
  buf2(0.0),
  buf3(0.0),
  buf4(0.0),
  buf5(0.0),
  buf6(0.0),
  buf7(0.0)
  {
    calculateFeedbackAmount();
  };
  double process(double inputValue);
  inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
  inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
  inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
  double cutoff;
  double resonance;
  double feedbackAmount;
  double buf0;
  double buf1;
  double buf2;
  double buf3;
  double buf4;
  double buf5;
  double buf6;
  double buf7;
};
class Notch {
public:
	Notch() :
		cutoff(0.1),
		resonance(1.0),
		buf0(0.0),
		buf1(0.0),
		buf2(0.0),
		buf3(0.0)
	{
		calculateFeedbackAmount();
	};
	double process(double inputValue);
	inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
	inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
    inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance / (1.0 - cutoff); }
private:
	double cutoff;
	double resonance;
	double feedbackAmount;
	double buf0;
	double buf1;
	double buf2;
	double buf3;

};
class Eq3{
public:
  Eq3():
    lg(1.0),
    mg(toLinear(-4.5)),
    hg(1.0)
  {
    lf.setResonance(0.0);
    mf1.setResonance(0.0);
    mf2.setResonance(0.0);
    hf.setResonance(0.0);
  }
  double process(double inputValue);
  void set(int sampleRate);
private:
  LP24 lf;
  HP24 mf1;
  LP24 mf2;
  HP24 hf;
  double lg;
  double mg;
  double hg;
};
class Clipper {
public:
	double process(double inputValue);
private:
	double k;
};
class LFO {
public:
	LFO() :
		out(0.0),
		mPI(2 * acos(0.0)),
		mFrequency(0.00001),
		mPhase(0.0),
		mSampleRate(44100.0) {
		updateIncrement();
	};
	void setFrequency(double Frequency);
	void setSampleRate(double sampleRate);
	void setPhase(double phase);
	double process(double inputValue);
private:
	const double mPI;
	double mFrequency;
	double mPhase;
	double mSampleRate;
	double mPhaseIncrement;
	void updateIncrement();
	double out;
};
class Compressor{
public:
  Compressor():
    peakOutput(0.0),
    peakB0Attack(1.0),
    outputGain(0.0),
    dynamicsAttackTime(0.0),
    dynamicsReleaseTime(0.5),
    dynamicsOutputGain(0.0) {
    set(44100);
  };
  void set(double sampleRate);
  double dynamics(double inputGain);
  double peakFinder(double inputValue);
private:
  double inputAbs;
  double peakfinderB0;
  double peakOutput;
  double fs;
  double peakfinderB0Attack;
  double peakfinderFinderA1;
  double peakfinderB0Release;
  double peakfinderReleaseTime;
  double peakB0Attack;
  double peakfinderA1;
  double outputGain;
  double dynamicsAttackTime;
  double dynamicsB0Attack;
  double dynamicsReleaseTime;
  double dynamicsB0Release;
  double dynamicsOutputGain;
  double dynamicsB0;
  
};
class EnvelopeFollower
{
public:
  EnvelopeFollower():
    envelope(0)
  {
    set(10.0,200.0,44100);
  };
  void set(double attackMs, double releaseMs, int sampleRate);
  void process(double input);
  double sidechain(double input, double sidechainSignal);
  double envelope;
private:
  double temp;
  double attack;
  double release;
};

class Limiter{
public:
  Limiter():
    attackCoeff(0.0),
    releaseCoeff(0.0),
    env(0.0),
    targetGain(1.0),
    currentGain(1.0),
    delayIndex(0)
  {
    set(0.001,400.0,-24.0,44100);
  };
  double process(double input);
  void set(double attackMs, double releaseMs, double thresholdDb,int sampleRate);
  void resetEnv();
private:
  double attackCoeff;
  double releaseCoeff;
  double env;
  double targetGain;
  double currentGain;
  int delayIndex;
  int delayLength;
  int sr;
  //double* delayLine;
  double threshold;
};
class Gate{
public:
  Gate():
  releaseTime(0.2),
  sr(44100),
  threshold(0.001),
  outputValue(0.0),
  gain(1.0),
  holdTime(1.0),
  attackTime(0.01){
    set(44100.0);
  };
  double process(double inputValue);
  void set(double sampleRate);
private:
  double releaseTime;
  double sr;
  double release;
  double threshold;
  double outputValue;
  double gain;
  int tick;
  double hold;
  double holdTime;
  double attack;
  double attackTime;
};
class Xcomp{
public:
  void set(int sampleRate);
  double process(double inputValue);
private:
  int sampleRate;
  double fRec2[2];
  double fRec1[2];
  double fRec0[2];
  double fConst0;
  double fConst1;
  double fConst2;
  double fConst3;
  double fConst4;
  double fTemp0;
  double fTemp1;
  double fTemp2;
  double output;
};

class Xlimiter{
public:
  void set(int sampleRate);
  double process(double inputValue);
private:
  int sampleRate;
  double fRec2[2];
  double fRec1[2];
  double fRec0[2];
  double b1;
  double b2;
  double attack;
  double release;
  double temp;
  double mag;
  double env;
  double output;
};

class SquwbsAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    SquwbsAudioProcessor();
    ~SquwbsAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SquwbsAudioProcessor)
    Limiter monoLimiterLeft;
    Limiter monoLimiterRight;
    LP36 MsubLPLeft;
    LP36 MsubLPRight;
    HP36 MHP1Left;
    HP36 MHP1Right;
    LP36 MLP1Left;
    LP36 MLP1Right;
    LP36 MLP2Left;
    LP36 MLP2Right;
    HP36 SHP1Left;
    HP36 SHP1Right;
    LP24 SLP1Left;
    LP24 SLP1Right;
    Eq3 SEQLeft;
    Eq3 SEQRight;
    Limiter TLimiterLeft;
    Limiter TLimiterRight;
    Gate TGateLeft;
    Gate TGateRight;
    Limiter finalLimiterLeft;
    Limiter finalLimiterRight;
    
    
    
    
};
