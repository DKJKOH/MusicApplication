

// MOST OF THE CODE HERE IS REFERRED FROM THE JUCE TUTORIAL : Customise the look and feel of your app
// WEBSITE: https://docs.juce.com/master/tutorial_look_and_feel_customisation.html

#include "button.h"


void Button::drawButtonBackground(
    juce::Graphics& g,
    juce::Button& button,
    const juce::Colour&
    backgroundColour,
    bool,
    bool isButtonDown)
{
    // Get local bounds of the button in the deckGUI
    auto buttonArea = button.getLocalBounds();

    // Sets edge of button
    auto edge = 3;

    // Set the shadow of the button
    g.setColour(juce::Colours::darkgrey.withAlpha(0.5f));
    // Fills the local bounds of button area to be darkgrey
    g.fillRect(buttonArea);

    // Offsets the button if user clicks the button which is -edge / 2, else it is -edge
    auto offset = isButtonDown ? -edge / 2 : -edge;

    // translate the button area 
    buttonArea.translate(offset, offset);

    // Sets the colour as the background color
    g.setColour(juce::Colours::lightsteelblue.withAlpha(0.4f));
    // Fills the rest of the button not colored
    g.fillRect(buttonArea);
}

// Most of the stuff is taken from LookAndFeel_V2 Class
void Button::drawButtonText(
    juce::Graphics& g,
    juce::TextButton& button,
    bool isMouseOverButton,
    bool isButtonDown)
{
    // gets font of button
    auto font = getTextButtonFont(button, button.getHeight());

    // Sets text button font
    g.setFont(font);

    // Sets the button color
    g.setColour(button.findColour(button.getToggleState() ? juce::TextButton::textColourOnId
        : juce::TextButton::textColourOffId)
        .withMultipliedAlpha(button.isEnabled() ? 1.0f : 0.5f));

    // Gets the coordinates where the text should be in
    auto yIndent = juce::jmin(4, button.proportionOfHeight(0.3f));
    auto cornerSize = juce::jmin(button.getHeight(), button.getWidth()) / 2;

    auto fontHeight = juce::roundToInt(font.getHeight() * 0.6f);
    auto leftIndent = juce::jmin(fontHeight, 2 + cornerSize / (button.isConnectedOnLeft() ? 4 : 2));
    auto rightIndent = juce::jmin(fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));


    // Code modification
    auto textWidth = button.getWidth() - leftIndent - rightIndent;

    auto edge = 4;

    // If button is down, offset value is edge / 2, otherwise, the value is 0
    auto offset = isButtonDown ? edge / 2 : 0;

    // Offsets the text to produce the illusion that the button is being pressed by user
    if (textWidth > 0)
        g.drawFittedText(
            button.getButtonText(),
            leftIndent + offset,
            yIndent + offset,
            textWidth,
            button.getHeight() - yIndent * 2 - edge,
            juce::Justification::centred,
            2);
}