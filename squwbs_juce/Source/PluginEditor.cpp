/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
struct scientificNumberType
{
    explicit scientificNumberType(T number, int decimalPlaces) : number(number), decimalPlaces(decimalPlaces) {}
    
    T number;
    int decimalPlaces;
};

template<typename T>
scientificNumberType<T> scientificNumber(T t, int decimalPlaces)
{
    return scientificNumberType<T>(t, decimalPlaces);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const scientificNumberType<T>& n)
{
    double numberDouble = n.number;
    
    int eToThe = 0;
    for(; numberDouble > 9; ++eToThe)
    {
        numberDouble /= 10;
    }
    
    // memorize old state
    std::ios oldState(nullptr);
    oldState.copyfmt(os);
    
    os << std::fixed << std::setprecision(n.decimalPlaces) << numberDouble << "e" << eToThe;
    
    // restore state
    os.copyfmt(oldState);
    
    return os;
}
//==============================================================================
SquwbsAudioProcessorEditor::SquwbsAudioProcessorEditor (SquwbsAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (100, 100);
    startTimerHz(60);
}

SquwbsAudioProcessorEditor::~SquwbsAudioProcessorEditor()
{
}
void SquwbsAudioProcessorEditor::timerCallback() {
    
    
    repaint();
    
}
//==============================================================================
void SquwbsAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);
    
    g.setColour (Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ('testing', getLocalBounds(), Justification::centred, 1);
    std::cout << scientificNumber(getProcessor().leftNow, 3)  << std::endl;

    //std::cout<<std::to_string(getProcessor().leftNow)<<std::endl;
}

void SquwbsAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
