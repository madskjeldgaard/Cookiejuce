#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

#if (MSVC)
#include "ipps.h"
#endif

#if USING_RUST
#include "{{ cookiecutter.__rust_lib_name }}/lib.h"
#endif

class PluginProcessor : public juce::AudioProcessor
{% if cookiecutter.add_default_parameters %}
  , public juce::AudioProcessorValueTreeState::Listener
{% endif %}
{
public:
    PluginProcessor();
    ~PluginProcessor() override;

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

  {% if cookiecutter.add_default_parameters %}
  // Parameters
    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
    {
        juce::AudioProcessorValueTreeState::ParameterLayout layout;

        // Default param1
        layout.add (std::make_unique<juce::AudioParameterInt> ("param1", "Default Param 1", 0, 12, 0));

        // Default param2
        layout.add (std::make_unique<juce::AudioParameterFloat> ("param2", "Default Param 2", 0.0f, 1.0f, 0.5f));

       // Default param3
        layout.add (std::make_unique<juce::AudioParameterChoice> ("param3", "Default Param 3", juce::StringArray { "Option 1", "Option 2", "Option 3" }, 0));

        return layout;
    }

    // Parameter stuff
    std::atomic<bool> parametersNeedUpdating;
    juce::AudioProcessorValueTreeState parameters { *this, nullptr, "Parameters", createParameterLayout() };
    void parameterChanged (const juce::String& parameterID, float newValue) override;
    void updateParameters();

    juce::AudioProcessorValueTreeState& getValueTreeState() { return parameters; }
{% endif %}

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginProcessor)
};
