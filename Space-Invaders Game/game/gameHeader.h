#pragma once
/*
*  gameFunctions.cpp
*     - The functions for the game program are in this file.
*
*  AUTHOR: Most of the work in this program was completed by Prof. Andy Harbert
*          Prof. Pat Smith has made modifications (December 2021)
* 
* Here's Jonathan Modifications: 
* 
*1.Restrict player ship movement to within the screen's left/right edges and bottom 20%.
*2.Introduce an enemy that moves horizontally across the top of the screen within left/right limits.
*3.Enemy movement should be fast and challenging to hit with a missile.
 4.If the missile hits the enemy, output "Hit!" to the console and set the missile Boolean to false.
 5.This will remove the missile from the screen.
*
*/
// includes go below

#include <iostream>
using namespace std;

// these two lines are specific to the SFML graphics library. 
#include <SFML/Graphics.hpp>
using namespace sf;

// Constants for the game 
//const float MISSILE_SPEED = 5.0f;
const float DISTANCE = 5.0f; // When the ship moves it moves 5 pixels at a time. 
const int WINDOW_WIDTH = 800; // window is 800 pixels wide
const int WINDOW_HEIGHT = 600;// window is 600 pixels vertically "high"

// Game Functions
void moveShip(Sprite& ship); 
//void updateMissile(Sprite& missile, Sprite& ship);
void moveEnemy(Sprite& enemyShip, bool& movingRight);