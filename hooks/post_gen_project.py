#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''Init git repository, add submodules.'''

import os
from subprocess import check_call

# Example list of submodules. Replace or extend this list as needed.
# Each tuple in the list contains the submodule URL and the desired output directory.
submodule_info = [
    ('https://github.com/juce-framework/JUCE', 'libs/JUCE'),
    ('https://github.com/sudara/melatonin_inspector.git', 'modules/melatonin_inspector'),
    ('https://github.com/sudara/cmake-includes.git', 'cmake-include/sudara-cmake'),
    ('https://github.com/free-audio/clap-juce-extensions.git', 'cmake-include/clap-juce-extensions')
]

def init_git_repo():
    print('\nInitializing new Git repository')
    check_call(['git', 'init'])

def add_submodules(submodules):
    for url, path in submodules:
        print(f'\nAdding submodule: {url} at {path}')
        check_call(['git', 'submodule', 'add', url, path])
        check_call(['git', 'submodule', 'update', '--init', '--recursive', '--', path])

def make_initial_commit():
    print('\nMaking initial Git commit')
    check_call(['git', 'add', '-A'])
    check_call(['git', 'commit', '-m', 'Initial commit with submodules'])

if __name__ == '__main__':
    print('\nRunning post-project-generation hook...')

    init_git_repo()
    add_submodules(submodule_info)
    make_initial_commit()

    print('\nYour project was successfully created with submodules!\n')

    post_info = ''' <3 Thanks for using Cookiejuce <3 '''

    print(post_info)
