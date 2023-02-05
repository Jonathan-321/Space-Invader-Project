#pragma once
/*
*  Circle.h
*     - The header file for the Circles Task. 
*  AUTHOR: Most of the work in this program was completed by Prof. Andy Harbert
*          Prof. Pat Smith modified the structure of the files, added a few bits and bobs.
*
*/

// Include file for normal c++ stuff
#include <iostream>
using namespace std;

// this is the include file for the SFML library.
// ** you -->MUST<-- have SFML installed at the top folder of the C: drive.
// This is because the configuration points to a folder on C:\SMFL-2.5.1
#include <SFML/Graphics.hpp>
using namespace sf;

// constants in use
const int WINDOW_WIDTH = 1000; // the window is 1000 pixels wide
const int WINDOW_HEIGHT = 600; // the window is 600 pixels high

// Functions that perform graphics action. 
CircleShape makeCircle(float radius, float x, float y);