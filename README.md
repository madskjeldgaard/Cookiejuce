# Cookiejuce – A command line tool for generating modern JUCE projects with CMake

![cookiejuce in action](cookiejuce.png) 

Easily generate beautiful JUCE projects and create audio, midi and music software with modern C++ using a simple command line tool interface.

When run, you are asked a series of questions, and a new project is generated based on your answers with everything correctly set up and named for your project.

Features:
- Uses [JUCE v7](https://github.com/juce-framework/JUCE)
- Projects generated [using cookiecutter](https://cookiecutter.readthedocs.io/en/stable/)
- CMake based JUCE workflow
- Supports C++20
- Support for the CLAP format
- vscode/neovim overseer runner tasks included
- [CPM](https://github.com/cpm-cmake/CPM.cmake) for dependency management
- Based on the Pamplejuce template, see [the original Pamplejuce readme for info about what it includes](PAMPLEJUCE_README.md):
    - Github action to automatically do cross platform builds and tests
    - Has Catch2 v3.4.0 for the test framework and runner.
    - Includes a Tests target and a Benchmarks target some examples to get started quickly.
    - Has [Melatonin Inspector](https://github.com/sudara/melatonin_inspector) installed as a JUCE module to help relieve headaches when building plugin UI.

The pamplejuce team has [nice explanation about using cmake and juce together](https://melatonin.dev/blog/how-to-use-cmake-with-juce/).

## Installation

It is required to have `cookiecutter` installed. You can install it with pip:

```bash
pip install cookiecutter
```
## Usage

```bash
cookiecutter https://github.com/madskjeldgaard/Cookiejuce
```

Then, answer the questionnare and a new project is generated.

After answering the questionnaire, a post project generation hook is run to set up git in your new project and pull all the submodules. This may take a while since it needs to download a lot of things.

## Credits

This project was originally based on [Pamplejuce](https://github.com/sudara/pamplejuce), a super nice template for creating nice JUCE projects.

