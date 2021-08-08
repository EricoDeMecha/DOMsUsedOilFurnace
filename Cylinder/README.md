# Cylinder modelling
Modelling the cylinder thickness using internal pressure, ultimate tensile strength and factor of safety 

Installing and compiling with matplotlibcpp

## Setup

```bash
    sudo apt-get install python-pip # install pip for python 2.7
    sudo pip2 install matplotlib  # install matplotlib for python 2.7
    sudo pip2 install numpy 
    sudo apt-get install python-tk # installing tkinter for python 2.7
```

## Usage

```bash
    mkdir build  &&  g++ ../cylinderThickness.cpp  -I/usr/include/python2.7 -I/usr/local/lib/python2.7/dist-packages/numpy/core/include -lpython2.7 && ./a.out
```