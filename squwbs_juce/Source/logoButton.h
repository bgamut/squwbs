/*
  ==============================================================================

    logoButton.h
    Created: 22 Feb 2018 9:13:47am
    Author:  Bernard Ahn

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "chooser.h"
//==============================================================================
/*
*/
class logoButton    : public Component
{
public:
    logoButton()
    //:convolver(16)
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.
        //logoComponent.setImage(logo);
        logoShadow.colour=Colour((uint8)256,(uint8)256,(uint8)256,(uint8)256);
        logoShadow.radius=0.5;
        logoShadow.offset=Point <int> (0.0,0.0);
        //addChildComponent(logoComponent);
        //glow.setGlowProperties(2.0,Colours::grey,Point<int>(0,0));
    }

    ~logoButton()
    {
    }

    void paint (Graphics& g) override
    {

        local=getLocalBounds();
        min=fmin(local.getWidth(),local.getHeight());
        area.setBounds(local.getCentreX()-min/2,local.getCentreY()-min/2,min,min);
        logoArea=area.reduced(min*5/32);
        //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background
        g.setColour (Colours::grey);
        //g.drawRect (getLocalBounds(), 1);
        //g.drawRect (area);// draw an outline around the component
        //g.drawRect (logoArea);
        logoShadow.drawForRectangle(g,logoArea);
        //glow.applyEffect(logo,g,1,255);
        g.setColour (Colours::white);
        g.drawImage(logo,logoArea.getX(),logoArea.getY(),logoArea.getWidth(),logoArea.getHeight(),0,0,209,209,false);
        
        g.setFont (14.0f);
        //convolver.applyToImage(logo,logo,logoArea);
        //convolver.createGaussianBlur(16);
        //g.drawText ("logoButton", getLocalBounds(),Justification::centred, true);   // draw some placeholder text
    }
    
    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }
    void mouseDoubleClick(const MouseEvent& e) override
    {
        doubleClicked=true;
        doubleClick();
        doubleClicked=false;
    }
    void load(float input) {
        int range = 12;
        uint8 number = (uint8)(256.0-range+abs(sin(float_Pi*input/2.0))*range);
        logoShadow.colour=Colour(number,number,number);
        //alpha=sin(float_Pi*input/2.0);
    }
    void doubleClick(){
        chooser.loadFile();
        midhighrms=chooser.threeband.midhighrms;
        midmidrms=chooser.threeband.midmidrms;
        midlowrms=chooser.threeband.midlowrms;
        sidehighrms=chooser.threeband.sidehighrms;
        sidemidrms=chooser.threeband.sidemidrms;
        sidelowrms=chooser.threeband.sidelowrms;
        midhighsd=chooser.threeband.midhighsd;
        midmidsd=chooser.threeband.midmidsd;
        midlowsd=chooser.threeband.midlowsd;
        sidehighsd=chooser.threeband.sidehighsd;
        sidemidsd=chooser.threeband.sidemidsd;
        sidelowsd=chooser.threeband.sidelowsd;
        
        
        std::cout<<String(midhighrms,3)<<", "<<String(midmidrms,3)<<", "<<String(midlowrms,3)<<", "<<String(sidehighrms,3)<<", "<<String(sidemidrms,3)<<", "<<String(sidelowrms,3)<<", "<<String(midhighsd,3)<<", "<<String(midmidsd,3)<<", "<<String(midlowsd,3)<<", "<<String(sidehighsd,3)<<", "<<String(sidemidsd,3)<<", "<<String(sidelowsd,3)<<std::endl;
        //std::cout<<String(1.0-(sidehighrms+sidehighsd),3)<<", "<<String(1.0-(sidemidrms+sidemidsd,3))<<", "<<String(1.0-(sidelowrms+sidelowsd,3))<<", "<<String(1.0-(midhighrms+midhighsd),3)<<", "<<String(1.0-(midmidrms+midmidsd),3)<<", "<<String(1.0-(midlowrms+midlowsd),3)<<", "<<String(1.0-(sidehighrms+sidehighsd),3)<<", "<<String(1.0-(sidemidrms+sidemidsd),3)<<", "<<String(1.0-(sidelowrms+sidelowsd),3)<<std::endl;
        chooser.threeband.reset();

    }
    int min;
    bool doubleClicked;
    Rectangle <int> area;
    Rectangle <int> local;
    Rectangle <int> logoArea;
    DropShadow logoShadow;
    //GlowEffect glow;
    //ImageConvolutionKernel convolver;
    //ImageComponent logoComponent;
    Image logo = ImageCache::getFromMemory(BinaryData::tinyLogo_png, BinaryData::tinyLogo_pngSize);
    chooser chooser;

    float midhighrms=0.5;
    float midmidrms=0.5;
    float midlowrms=0.5;
    float sidehighrms=0.5;
    float sidemidrms=0.5;
    float sidelowrms=0.5;
    float midhighsd=0.25;
    float midmidsd=0.25;
    float midlowsd=0.25;
    float sidehighsd=0.25;
    float sidemidsd=0.25;
    float sidelowsd=0.25;


    //ImageButton button;
    //RectanglePlacement placement;
    //float alpha=0.0;
private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (logoButton)
};
