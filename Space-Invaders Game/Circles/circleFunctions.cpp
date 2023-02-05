#include "Circle.h"
/*
*  CircleFunctions.cpp
*     - A simple example of the SFML graphics library.
*     - This program draws circles on a black background
*  AUTHOR: Most of the work in this program was completed by Prof. Andy Harbert
*          Prof. Pat Smith has made modifications (December 2021)
*
*/

// create a new instance of a circle with specified radius and position
// Note: the graphics library specifies location of things using the upper left corner
// of the bounding box of object, so x,y will be the upper left "corner" of the circle

/* 
 *  MakeCircle - A function to go through steps necessary to create a circle object
 *    that can be displayed in a window. 
 *    This function simply creates a CircleShape object and sets it properties.
 *  Inputs: 
 *      radius - SFML uses floating point values to describe the radius in pixels
 *      x - SFML uses a float to describe the horizontal position
 *      y - SFML uses a float to describe the vertical position
 *  Returns:
 *      A circleShape object is returned, with parameters for fill and line color,
 *         thickness and x and y location all set up.
 * 
 *  ** IMPORTANT ** The "origin point of "0,0" is the upper left corner of the window
 *     The y values get larger as you move down the window
 *     the x values get larger as you move right in the window. 
 * 
 */
CircleShape makeCircle(float radius, float x, float y)
{
	CircleShape circle(radius);				 // create the circleShape Sprite
	circle.setFillColor(Color::Transparent); // Make the interior clear
	circle.setOutlineColor(Color::Green);    // Make the outline, the circle, Green
	circle.setOutlineThickness(1);           // Make the line 1 pixel thick
	circle.setPosition(x, y);                // The upper right "corner" of 
	                                         //   the square containing the circle 
											 //   is set to x and y. 
	return circle;
}