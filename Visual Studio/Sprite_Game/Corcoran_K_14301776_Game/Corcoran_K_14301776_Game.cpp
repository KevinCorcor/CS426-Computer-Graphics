// OpenGL_Game.cpp
// Extension of Bare bones version of "Happy Vikings" by C.Markham Jan 2015
// Kevin Corcoran 14301776 - April 2018

#include "stdafx.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>
#include <windows.h>    // Required for sound only (consider OpenAL), 
#include <mmsystem.h>   // Again only required for sound only
#include <freeglut.h>   // GLUT OpenGL Utility Toolkit
#include "Sprite.h"     // Prototype Sprite class

// 3 Sprites are used in the "game"
Sprite expro;//explosion
Sprite player; //spaceship
Sprite ball; //asteroid
Sprite beam;//amo
Sprite background;//stars

// Score data and method
//text
char welcome_text[20];
char health_text[20];
char Game_text[20];
char score_text[20];
//booleans
bool keyStates[256] = {false};	//enables more that one key to be utilised simultaneously
bool playing = false; //game in progress or not
bool fire = false;	//shooting or not
bool welcome = true; //display welcome screen?
bool destroyed = false; //display explosion sprite?
//counters
int score=0;
int health = 5;

void keyOperations (void) //with the help of http://www.swiftless.com/tutorials/opengl/keyboard.html
{  
	if (keyStates['a']) 
	{
		player.specific_frame(4);

		if(player.sprite_x_position>=0)//keep within frame
		{	
			player.sprite_x_position-=9;
		}

		player.direction=true;
	}

	if (keyStates['d']) 
	{ 
		player.specific_frame(5);

		if(player.sprite_x_position+player.sprite_width<=640)//keep within frame
		{
			player.sprite_x_position += 9;
		}

		player.direction=true;
	}
	if (keyStates['w']) 
	{ 
		player.advance_frame(6,7);

		if(player.sprite_y_position+player.sprite_height<=480)//keep within frame
		{
			player.sprite_y_position += 3;
		}

		player.direction=true;
	}
	if (keyStates['s']) 
	{ 
		player.specific_frame(0);

		if(player.sprite_y_position>=0)//keep within frame
		{
			player.sprite_y_position -= 3;
		}

		player.direction=true;
	}

	if (keyStates[' '])
	{
		fire = true; 
	}

	if (keyStates['q'])
	{
		glutLeaveMainLoop();
	}
} 


// Callback function called each time screen is to be redrawn (called by OS not you directly)
static void display(void)                                 
{	
	if(playing)
	{
		keyOperations();
	}	
	// Keep game logic out of display()...
	  
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen and the Depth Buffer
	background.drawSprite();							// Draw background at X,Y in a given direction
	player.drawSprite();								// Draw player	
	ball.drawSprite();// Draw ball 

	if(destroyed)
	{
		expro.drawSprite();
	}

	if(fire)
	{
		beam.drawSprite();
	}
	else //if i am not firing make sure the beam is ready in the position of the player(spaceship)
	{
		beam.sprite_x_position = (player.sprite_x_position + (player.sprite_width)/2)-2; 
		beam.sprite_y_position = player.sprite_y_position+player.sprite_height-9;
	}

	sprintf(score_text,"Score: %d",score);              // Display text 
	Sprite::text(290,460,score_text);
	sprintf(health_text,"Health: %d",health);              // Display text 
	Sprite::text(5,460,health_text);
	
	if(welcome)
	{
		sprintf(welcome_text,"press any key to begin");              // Display text 
		Sprite::text(230,320,welcome_text);
		player.sprite_x_position = 288;
	}
	
	if(!playing && !welcome && health<=0)//if i have lost
	{
		destroyed = true;
		sprintf(Game_text,"GAMEOVER - FINAL SCORE: %d",score);              // Display text 
		Sprite::text(195,320,Game_text);
		//reset counters
		health = 5;			
		score = 0;
		//reset position of player(spaceship)
		player.sprite_x_position = 288;
		player.sprite_y_position = 0;
		player.specific_frame(0);
		//reset position of beam
		beam.sprite_x_position = 318;
		beam.sprite_y_position = player.sprite_y_position+player.sprite_height-9;
	}
	else if(!welcome && !playing)
	{
		welcome = true;
	}

	glutSwapBuffers();  // Display buffer just drawn and then switch to draw on the other buffer
	
	if(!playing && !welcome) 
	{
		Sleep(5000);
		destroyed =false;
	}
}

// Callback function to allow dynamic resizing of runtime display
static void resize(int width, int height)
{
    glViewport(0, 0, width, height);
	Sprite::spriteModeOn(0,0);  // (0,0) Causes orginal screen size to be reused
}


void keyPressed(unsigned char key, int x, int y) 
{  
	keyStates[key] = true; // Set the state of the current key to pressed 
	playing = true;
	welcome=false;
}  
  
void keyUp(unsigned char key, int x, int y) 
{  
	keyStates[key] = false; // Set the state of the current key to not pressed
} 


// Game loop
// static void idle()    // if using  glutIdleFunc(idle); this line should replace the one below
static void idle(int v)  // Runs between frame updates in doublebuffer mode, game logic goes here
{
	if(playing)
	{
		ball.advance_projectile();      // Advance ball 
	  
		if(ball.sprite_y_position<-80)  //passes the spacehip
		{ 	   
			health--;
			ball.sprite_y_position=480;
			ball.sprite_y_velocity=50+(rand()%200);
			ball.sprite_x_position=rand()%576;
		}
				
		ball.advance_frame(0,6);  // Cycle through 7 images [0,6]
			
		if(fire)
		{
			beam.advance_projectile2();

			if(beam.sprite_y_position>480) //once the beam leaves the page 
			{
				fire = false;
				//reset the beam
				beam.sprite_x_position = (player.sprite_x_position + (player.sprite_width)/2)-2;
				beam.sprite_y_position = player.sprite_y_position+player.sprite_height-9;
				beam.sprite_y_velocity = (0.05+(-0.15*beam.sprite_y_position)*0.6);
			}
		}

		if(player.collision(ball))
		{
			expro.sprite_x_position = ball.sprite_x_position;
			expro.sprite_y_position = ball.sprite_y_position;
			destroyed = true;
			ball.sprite_y_position=480;
			ball.sprite_y_velocity=50+(rand()%200);
			ball.sprite_x_position=rand()%576;
			health--;
		}

		if(beam.collision(ball))
		{
			expro.sprite_x_position = ball.sprite_x_position;//+(ball.sprite_width/2);
			expro.sprite_y_position = ball.sprite_y_position;
			destroyed = true;
			score++;
			ball.sprite_y_position=480;
			//ball.sprite_y_velocity=50+(rand()%200);
			ball.sprite_x_position=rand()%576;
			beam.sprite_y_velocity = (0.05+(-0.15*player.sprite_height)*0.6);
		}
		
		/*so long as the ship is not moving*/
		if(!(keyStates['w']||keyStates['a']||keyStates['s']||keyStates['d']))//if i am not moving
		{
			player.advance_frame(1,3);
		}

		if(health <= 0)
		{
			//explode the ship and reset the game
			expro.sprite_x_position = player.sprite_x_position;
			expro.sprite_y_position = player.sprite_y_position;
			destroyed = true;
			playing = false;
			
		}
	}
	glutPostRedisplay();      // Send message to ask for screen to be redrawn
	glutTimerFunc(10,idle,0); // Restart the timer (remove line if using the more common glutIdleFunc(idle) approach)
}

/* Program entry point - starts here */
int main(int argc, char *argv[])
{
	Sprite::spriteModeOn(640,480);
	PlaySound(L"V.wav",NULL, SND_LOOP| SND_ASYNC); //http://freemusicarchive.org/tag/8-bit/
	expro.load("expl.bmp", 1,1,0,  0,64,64,true); //https://camo.githubusercontent.com/10ebee480315ed66c2bfa946d8d0b85e7443a258/68747470733a2f2f7261772e6769746875622e636f6d2f77696b692f47617261676547616d65732f546f7271756532442f47657474696e675f537461727465645f696d616765732f496d706163745f4578706c6f73696f6e2e706e67
	player.load("spaceship.bmp",8,1,288,0,64,64,false);  //made myself
	ball.load("aste4_bmp.bmp",7,1,290,500,64,64,true); //https://camo.githubusercontent.com/593a5291887532e6f8d7c231a1db63de3ff929d0/68747470733a2f2f7261772e6769746875622e636f6d2f77696b692f47617261676547616d65732f546f7271756532442f47657474696e675f537461727465645f696d616765732f61737465726f6964732e706e67
	background.load("stars.bmp",1,1,0,0,640,480,true); //https://alpha.wallhaven.cc/wallpaper/41034
	beam.load("beam2.bmp",1,1,318,player.sprite_y_position+player.sprite_height-9,4,8,true);
    glutReshapeFunc(resize);			// Called when window is resized (not required)
	glutDisplayFunc(display);			// Callback function to redraw, an event created by glutPostRedisplay()
	glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses  
	glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events 	
	glutTimerFunc(10,idle,0);           // Use timer callback for more consistent timing
	glutMainLoop();						// Start main loop running (go!)
    
	return EXIT_SUCCESS;
}


