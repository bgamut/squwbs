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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "chooser.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
chooser::chooser ():
changed(false)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]
    //setSize (600, 400);
	formatManager.registerBasicFormats();
    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

chooser::~chooser()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

void chooser::loadFile()
{
	FileChooser myChooser("Please select the reference file you want to load.", File::getSpecialLocation(File::userHomeDirectory), "*");
	myChooser.browseForFileToOpen();
	File r(myChooser.getResult());
	if (r.exists()) {
		ScopedPointer<AudioFormatReader> reader(formatManager.createReaderFor(r));
		if (reader != nullptr) {
			int testLength = reader->lengthInSamples;
			//threeband.setSampleRate(reader->sampleRate);
			fourband.setSampleRate(reader->sampleRate);
			fileBuffer.setSize(2, testLength);
			reader->read(&fileBuffer, 0, testLength, 0, true, true);
			int numInputChannels = fileBuffer.getNumChannels();
			AudioBuffer<float> analysisBuffer(2, testLength);
			AudioSourceChannelInfo channelInfo(analysisBuffer);
			float* left = new float[testLength];
			float* right = new float[testLength];
			if (numInputChannels == 1) {
				for (int index = 0; index < testLength; index++) {
					left[index] = fileBuffer.getSample(0, index);
					right[index] = fileBuffer.getSample(0, index);
				}
			}
			else {
				for (int index = 0; index < testLength; index++) {
					left[index] = fileBuffer.getSample(0, index);
					right[index] = fileBuffer.getSample(1, index);
				}
			}

			//threeband.runStats(left, right, testLength);
			fourband.runStats(left, right, testLength);
			std::cerr<< std::to_string(fourband.midtoprms) << "," << std::to_string(fourband.midhighrms) << "," << std::to_string(fourband.midmidrms) << "," << std::to_string(fourband.midlowrms) << "," << std::to_string(fourband.sidetoprms) << "," << std::to_string(fourband.sidehighrms) << "," << std::to_string(fourband.sidemidrms) << "," << std::to_string(fourband.sidelowrms) << "," << std::to_string(fourband.midtopsd) << "," << std::to_string(fourband.midhighsd) << "," << std::to_string(fourband.midmidsd) << "," << std::to_string(fourband.midlowsd) << "," << std::to_string(fourband.sidetopsd) << "," << std::to_string(fourband.sidehighsd) << "," << std::to_string(fourband.sidemidsd) << "," << std::to_string(fourband.sidelowsd) << std::endl;
			String MyFilePath = "C:\\Users\\bernard\\Desktop\\musicData.txt";
			File w(MyFilePath);

			w.appendText(std::to_string(fourband.midtoprms));
			w.appendText(",");
			w.appendText(std::to_string(fourband.midhighrms));
			w.appendText(",");
			w.appendText(std::to_string(fourband.midmidrms));
			w.appendText(",");
			w.appendText(std::to_string(fourband.midlowrms));
			w.appendText(",");
			w.appendText(std::to_string(fourband.sidetoprms));
			w.appendText(",");
			w.appendText(std::to_string(fourband.sidehighrms));
			w.appendText(",");
			w.appendText(std::to_string(fourband.sidemidrms));
			w.appendText(",");
			w.appendText(std::to_string(fourband.sidelowrms));
			w.appendText(",");
			w.appendText(std::to_string(fourband.midtopsd));
			w.appendText(",");
			w.appendText(std::to_string(fourband.midhighsd));
			w.appendText(",");
			w.appendText(std::to_string(fourband.midmidsd));
			w.appendText(",");
			w.appendText(std::to_string(fourband.midlowsd));
			w.appendText(",");
			w.appendText(std::to_string(fourband.sidetopsd));
			w.appendText(",");
			w.appendText(std::to_string(fourband.sidehighsd));
			w.appendText(",");
			w.appendText(std::to_string(fourband.sidemidsd));
			w.appendText(",");
			w.appendText(std::to_string(fourband.sidelowsd));
			//w.appendText(",");
			w.create();
			delete[] left;
			delete[] right;
            changed=true;
		}
	}
}


