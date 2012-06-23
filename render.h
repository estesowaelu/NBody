#ifndef _RENDER_H
#define _RENDER_H

#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "OpenGL/gl.h"
#include "GLUT/glut.h"

class Render
{
public:
	
	//constructor definition
	Render();
	//destructor definition
	~Render();

	// These functions are defined public so they can be called by the main function in main.cpp
	void display(void);
	void init(void);
	void reshape(int w, int h);
	void mouseClick(int button, int state, int x, int y);
	void mouseMove(int x, int y);
	void keyPos(unsigned char key, int x, int y);
	
private:
	// These functions are private and cannot be called anywhere outside of render class
	void drawTextureBox(void);
	void clamp(float v0, float v1, float v2);

	// Variables used in the member functions of render class
	float eye[3];
	float rot[3];
	int Wx, Wy;
	int LEFT, MIDDLE, RIGHT;
	int mButton;
	int mOldX, mOldY;
	
	GLUquadricObj *qobj;
	void drawPlanetarySystem(void);
	void drawSun(void);
	void drawMercury(void);
	void drawVenus(void);
	void drawEarth(void);
	void drawMoon(void);
	void drawMars(void);
	void drawJupiter(void);
	void drawSaturn(void);
	void drawUranus(void);
	void drawNeptune(void);


};

#endif
