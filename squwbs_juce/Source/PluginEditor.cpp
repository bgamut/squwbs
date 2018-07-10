/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

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
    std::cout<<std::to_string(getProcessor().leftNow)<<std::endl;
}

void SquwbsAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
