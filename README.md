# Lana Tetris [![Build Status](https://travis-ci.org/andystanton/lana-tetris.png?branch=master)](https://travis-ci.org/andystanton/lana-tetris)

An implementation of Tetris in C++. I wrote this as a way of learning C++ and basic game development. It makes use of the [GLFW library](http://www.glfw.org) and [CMake](http://www.cmake.org/) to build the project.

![](http://andystanton.github.io/images/lana-tetris.png) ![](http://andystanton.github.io/images/lana-tetris-gameplay.png)

## Requirements

 * A C++11 compiler
 * [CMake >= 2.8](http://www.cmake.org/cmake/resources/software.html)

## Quick Start

Clone the project:

```sh
git clone https://github.com/andystanton/lana-tetris.git --recursive && cd lana-tetris  
```

Run the following commands to generate the makefile and build:

```sh
./configure
make
```

This will create the lana-snake executable in the project directory.

## Generating project files for your IDE

Run the following command to generate the project files for your IDE:

```sh
cmake . -G {ide_name}
```

For more information on CMake's project generators and a full list of supported platforms and IDEs, see the [documentation](http://www.cmake.org/Wiki/CMake_Generator_Specific_Information).

## Gameplay

<a href="http://www.youtube.com/watch?feature=player_embedded&v=-ECDB9oacdE
" target="_blank"><img src="http://img.youtube.com/vi/-ECDB9oacdE/0.jpg" 
alt="Lana Tetris Gameplay" width="320" height="240" border="10" /></a>

## Controls

 * A : Rotate Left
 * S : Rotate Right
 * Left : Move Left
 * Right : Move Right
 * Down : Downward Acceleration
 * Space : Pause

## Debug Controls

### Gameplay Controls

 * Q : Regular Mode
 * W : Frozen Mode
 * E : Infinity Mode
 * - : Slow Down
 * = : Speed Up

### Tetromino Switching

 * 1 : I Tetromino
 * 2 : O Tetromino
 * 3 : T Tetromino
 * 4 : J Tetromino
 * 5 : L Tetromino
 * 6 : S Tetromino
 * 7 : Z Tetromino
 * 8 : Debug Tetromino

## Disclaimer

This software is written purely for academic purposes as an exercise in learning C++ and game development. Tetris is a registered trademark and copyright of Tetris Holding.
