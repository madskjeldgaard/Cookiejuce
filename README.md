# Cookiejuce – A command line tool for generating modern JUCE projects with CMake

Easily generate beautiful JUCE projects and create audio, midi and music software with modern C++.

When run, you are asked a series of questions, and a new project is generated based on your answers with everything correctly set up and named for your project.

Features:
- Projects generated [using cookiecutter](https://cookiecutter.readthedocs.io/en/stable/)
- CMake based JUCE workflow
- C++20
- Support for the CLAP format
- vscode/neovim overseer runner tasks included
- [CPM](https://github.com/cpm-cmake/CPM.cmake) for dependency management
- Based on the Pamplejuce template, see [the original Pamplejuce readme for info about what it includes](PAMPLEJUCE_README.md)

## Installation

It is required to have `cookiecutter` installed. You can install it with pip:

```bash
pip install cookiecutter
```
## Usage

```bash
cookiecutter https://github.com/madskjeldgaard/cookiejuce
```

Then, answer the questionnare and a new project is generated.

## Credits

This project was originally based on [Pamplejuce](https://github.com/sudara/pamplejuce), a super nice template for creating nice JUCE projects.

