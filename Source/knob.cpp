

// MOST OF THE CODE HERE IS REFERRED FROM THE JUCE TUTORIAL : Customise the look and feel of your app
// WEBSITE: https://docs.juce.com/master/tutorial_look_and_feel_customisation.html

#include "knob.h"


void Knob::drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
    const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider&)
{
    // Calculates the radius of the knob
    auto radius = (float)juce::jmin(width / 2, height / 2) - 4.0f;

    // Centre X position of the knob
    auto centreX = (float)x + (float)width * 0.5f;

    // Centre Y position of the knob
    auto centreY = (float)y + (float)height * 0.5f;

    // Radius X of the knob
    auto rX = centreX - radius;

    // Radius Y of the knob
    auto rY = centreY - radius;

    // Radius Width of the knob
    auto rW = radius * 2.0f;

    // Calculates the angle of the knob after turn
    auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

    // Makes the knob blue
    g.setColour(juce::Colours::darkgrey);
    g.fillEllipse(rX, rY, rW, rW);

    // Sets outline of the knob
    g.setColour(juce::Colours::white);
    g.drawEllipse(rX, rY, rW, rW, 1.0f);

    // Draw the pointer in the knob
    juce::Path p;

    // Length of the pointer
    //auto pointerLength = radius * 0.33f;

    auto pointerLength = radius * 0.60f;

    // Thickness of the pointer
    auto pointerThickness = 2.0f;

    auto halfPointerthickness = 1.0f;

    auto firstCoordinateX = -pointerThickness * 0.5f;

    // Draws the triangle which is the pointer itself
    p.addTriangle(
        -pointerThickness * 0.5f, -radius,
        firstCoordinateX - 1.0f, -radius + pointerLength,
        firstCoordinateX + 1.0f, -radius + pointerLength);

    // transforms the rectangle (rotates) about its centreX and centreY as its coordinates
    p.applyTransform(juce::AffineTransform::rotation(angle).translated(centreX, centreY));

    // Fills the pointer to the color
    g.setColour(juce::Colours::white);
    g.fillPath(p);
}