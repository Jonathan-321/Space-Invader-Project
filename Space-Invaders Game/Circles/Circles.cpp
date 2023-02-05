#include "Circle.h"
 /*
 *  Circles.cpp
 *     - A simple example of the SFML graphics library.
 *     - This program draws circles on a black background
 *  AUTHOR: Most of the work in this program was completed by Prof. Andy Harbert
 *          Prof. Pat Smith has made modifications (December 2021)
 * 
 */

// ** You may have to move the *.lib files from c:\sfml-2.5.1\bin to the debug folder under this 
//       solution
// ** In addition, if you run this in release mode, you'll have to move the *.lib files 
//       to the release folder under this solution. 

int main()
{
	// Create the display window.  A frame rate of 60 means we'll update 60 times/second
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Some circles");
	window.setFramerateLimit(60);

	// The console window is still there - the window created in the lines above
	//    are a different window. 
	// Display some text on the console window. - NOTE -- This console window
	//    can be a hand debugging tool!
	cout << "cout's still work, but they show up in the \"console\" window, "
		<< "not the graphics window" << endl;

	// This is the main "game loop" that will run for the duration of the program (until the window 
	// is closed -- usually by the user clicking the "X" in the upper right corner of the window)
	// 
	// What follows is the basic loop we'll use for our game as well. Make sure you understand what
	//     is going on!
	// 
	// Each iteration of the loop:
	//   1. Handle any events (mouse events, etc.) that occurred since the last iteration of the loop. 
	//      This event handling requires another loop because there could be multiple events waiting 
	//		to be processed. For now, we need this just to be able to close the window.
	//   2. After handling events, we'll make one frame of the animation. 
	//       Inside that Loop (the while loop below) We take the following steps:
	//       1. Clear the screen.
	//       2. Update positions of things, etc, and create/draw graphics objects in 
	//	        their positions for this frame. The drawing is actually done "off screen" to a temporary 
	//		    memory area. Nothing will show up on screen until the step below.
	//       3. Call window.display() to push everything to the screen. This completes this frame, 
	//		    then we'll loop back and build the next frame. 

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// do not modify the poll event loop
		Event event;
		while (window.pollEvent(event)) // as long as there are events, deal with them.
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			// other event handling would be taken care of by other "else if"
			//   statements.  Things like detecting and taking care of 
			//   keyboard actions or mouse actions. 
		}

		// clear the window with black color -- This resets the window for display and animation
		window.clear(Color::Transparent);

		// This is just an example to show you how to make circles
		// See the 'makeCircle()' function defined above
	/*	CircleShape c1 = makeCircle(50, 5, 5);
		CircleShape c2 = makeCircle(10, 600, 400);*/

		// This "draw" method on the window does not display it on the screen. 
		// It draws it in the Window in memory.  
		// We'll draw the entire window and all its contents below when we 
		// execute the "window.display()" function. 

		//window.draw(c1); // c1 is a circle, draw it into the window
		//window.draw(c2); // c2 is a different circle. 

		// you will replace the above example code with a loop that 
		// does the following 20 times:
		// 

		for (int i = 0; i < 20; i++) {
			CircleShape circle( 30.f);
			int x = (i % 5) * 100;
			int y = (i / 5) * 100;
			circle.setPosition(x,y);
			circle.setFillColor(Color::Green);
			window.draw(circle);
		}

		

		// {
		//		CircleShape circle = makeCircle(...parameters...);
		//		window.draw(circle);
		//		...calculate new values for next circle...
		// }
		// Note in the above that you can re-use the same circle
		// instance each time through the loop

		// end the current frame; put everything on the screen
		window.display();
	}

	return 0;
}