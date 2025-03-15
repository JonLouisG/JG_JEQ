/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/

struct CustomRotarySlider : juce::Slider
{
    CustomRotarySlider() : juce::Slider(Slider::RotaryHorizontalVerticalDrag,
                                        juce::Slider::TextEntryBoxPosition::NoTextBox)
    {
        
    }
};
class JG_JEQAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    JG_JEQAudioProcessorEditor (JG_JEQAudioProcessor&);
    ~JG_JEQAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JG_JEQAudioProcessor& audioProcessor;
    
    CustomRotarySlider peakFreqSlider,
    peakGainSlider,
    peakQualitySlider,
    lowCutFreqSlider,
    highCutFreqSlider,
    lowCutSlopeSlider,
    highCutSlopeSlider;
    
    using APVTS = juce::AudioProcessorValueTreeState;
    using Attachment = APVTS::SliderAttachment;
    
    Attachment peakFreqSliderAttachment,
                peakGainSliderAttachment,
                peakQualitySliderAttachment,
                lowCutFreqSliderAttachment,
                highCutFreqSliderAttachment,
                lowCutSlopeSliderAttachment,
                highCutSlopeSliderAttachment;
    
    std::vector<juce::Component*> getComps();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JG_JEQAudioProcessorEditor)
};
