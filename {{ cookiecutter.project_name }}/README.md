# {{ cookiecutter.project_name }}

## By {{ cookiecutter.company_name }}

{{ cookiecutter.plugin_description }}

Generated using [Cookiejuce](github.com/madskjeldgaard/Cookiejuce).

## Building

Configure:
```bash
cmake -S . -B build
```

Build:
```bash
cmake --build build
```

The plugins are now copied to your system.

Run standalone (on MacOS):
```bash
./build/{{ cookiecutter.project_name }}_artefacts/Standalone/{{ cookiecutter.project_name }}.app/Contents/MacOS/{{ cookiecutter.project_name }}
```


