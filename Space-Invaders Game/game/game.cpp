#include "gameHeader.h"
/*
*  game.cpp
*     - A simple game loop that allows you to move the ship
*       and eventually fire a missile.
*  AUTHOR: Most of the work in this program was completed by Prof. Andy Harbert
*          Prof. Pat Smith has made modifications (December 2021)
*
*/
int main()
{
	// Create the window for graphics. 
	//  The "aliens" is the text in the title bar on the window. 
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");

	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.

	// a Texture is an image of pixels. You can load a .png file
	//   or a bitmap file.  These files are in the "Resource files" section of
	//   the solution explorer. 



	Texture enemyTexture;
	if (!enemyTexture.loadFromFile("alien.bmp"))
	{
		cout << "Unable to load enemy texture!" << endl;
		exit(EXIT_FAILURE);
	}

	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}

	// We use the star texture as a background for space in the window.
	//  it makes it more interesting. :)
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}

	// An alien bitmap is provided in the Resource Files... 
	//  Perhaps you'll want to make your own alien though...

	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background; // the background is a sprite, though we'll never move it around. 
	background.setTexture(starsTexture); // load the starsTexture object into the sprite.
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// create sprite and texture it
	Sprite ship;
	ship.setTexture(shipTexture);


	// creating a sprite for the enemyShip;
	Sprite enemyShip;
	enemyShip.setTexture(enemyTexture);

	// setting the initial position of the enemy

	float enemyX = window.getSize().x / 2.0f;
	float enemyY = window.getSize().y * 0.2f;

	enemyShip.setPosition(enemyX, enemyY);

	// Track if the enemy was hit

	bool isenemyHit = false;

	// setting the boolean enemyDirection right 

	bool movingRight = true;
	// Texture for the missile 
	Texture missileTexture;
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "unable to load missile!" << endl;
		exit(EXIT_FAILURE);
	}
	// Then create the missile Sprite...  

	Sprite missile;
	missile.setTexture(missileTexture);


	// initial position of the ship will be approx middle of screen
	float shipX = WINDOW_WIDTH - window.getSize().x / 4.0f;
	float shipY = WINDOW_HEIGHT - window.getSize().y / 4.0f;
	//float missileX = window.getSize().x / 2.0f;


	ship.setPosition(shipX, shipY);

	bool isMissileInFlight = false; // used to know if a missile is 'on screen'.

	//float missileSpeed = 10.0f;


	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		// This while loop checks to see if anything happened since last time
		// we drew the window and all its graphics. 
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) // Did the user kill the window by pressing the "X"?
				window.close();
			else if (event.type == Event::KeyPressed) // did the user press a key on the keyboard?
			{
				if (event.key.code == Keyboard::Space && !isMissileInFlight)
				{
					isMissileInFlight = true;

					// You add the code to initialize missile position

					/*Vector2f pos = ship.getPosition();
					missile.setPosition(pos.x, pos.y);*/

					missile.setPosition(ship.getPosition().x, ship.getPosition().y - missile.getGlobalBounds().height);


					//  You should have created a missile sprite 
					// above the main loop, maybe around line 60? 
				}
			}
		}
		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================


		//updateMissile(missile, ship);

		//window.clear();

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);

		//detect key presses to update the position of the ship. 
		//See moveShip() function above.
		moveShip(ship);

		// draw the ship on top of background 
		// (the ship from previous frame was erased when we drew background)
		window.draw(ship);


		if (isMissileInFlight)
		{
			// ***code goes here to handle a missile in flight
			// 
			// Draw the missile, 

			window.draw(missile);
			missile.move(0, -DISTANCE);


			// move it "up" the screen by decreasing 'y' and then use 'setPosition()' 
			//     to place it at its new location. 



			// Don't forget to draw it after you change the missiles location. 
			// Don't forget to see if the missile is off screen!
			// if it's moved off the top, set the boolean to false!

			if (missile.getPosition().y <= 0)
			{
				isMissileInFlight = false;

			}

			window.draw(missile);
			missile.move(0, -DISTANCE);



			//Check if the missile has hit the enemy

			FloatRect missileBounds = missile.getGlobalBounds();
			FloatRect enemyBounds = enemyShip.getGlobalBounds();

			if (missileBounds.intersects(enemyBounds))
			{
				// Output a hit message
				cout << "Hit!" << endl;

				// Set the missile boolean to false
				isMissileInFlight = false;

				// Set the enemy hit boolean to true
				isenemyHit = true;

				//// checking if the enemy was hit 
				//if (isenemyHit) {

				//	// Hide the missile 
				//	missile.setPosition(-100, -100);
				//	//Reset the enemy hit 
				//		isenemyHit = false;

				//}
			}

		}

		moveEnemy(enemyShip, movingRight);

		// drawing the enemy 
		window.draw(enemyShip);
		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();
		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}

