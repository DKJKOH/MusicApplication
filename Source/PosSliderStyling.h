#pragma once
#include <JuceHeader.h>

class PosSliderStyling : public juce::LookAndFeel_V4
{
public:
    PosSliderStyling()
    {
        setColour(juce::Slider::trackColourId, juce::Colours::white.withAlpha(0.5f));

        // Highlights text yellow that is semi opaque
        setColour(juce::Slider::textBoxHighlightColourId, juce::Colours::yellow.withAlpha(0.5f));

    };
};