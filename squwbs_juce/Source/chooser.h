/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.1.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "ThreeBandEQ.h"
#include "FourBandEQ.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class chooser  : public Component
	             //,public AudioAppComponent
{
public:
    //==============================================================================
    chooser ();
    ~chooser();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]
	void loadFile();
	AudioFormatManager formatManager;
	ScopedPointer<AudioFormatReaderSource> readerSource;
	AudioFormatReader* reader;
	ThreeBandEQ threeband;
	FourBandEQ fourband;
	AudioSampleBuffer fileBuffer;
    bool changed;
private:
 
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (chooser)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
