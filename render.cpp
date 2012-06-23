#include "render.h"

#define TIMER 33

using namespace std;

void recomputeFrame(int value);

float sunrot = 0.0;
float mercrot = 0.0;
float venrot = 0.0;
float earthrot = 0.0;
float moonrot = 0.0;
float marsrot = 0.0;
float juprot = 0.0;
float satrot = 0.0;
float urrot = 0.0;
float neprot = 0.0;

float mercorbit = 0.0;
float venorbit = 0.0;
float earthorbit = 0.0;
float moonorbit = 0.0;
float marsorbit = 0.0;
float juporbit = 0.0;
float satorbit = 0.0;
float urorbit = 0.0;
float neporbit = 0.0;

bool paused = false;
bool reversed = false;

void recomputeFrame(int value) {
	if(!paused){
		if(!reversed){
			sunrot += 0.040f;
			mercrot += 0.170f;
			venrot += 0.004f;
			earthrot += 1.000f;
			moonrot += 27.435f;
			marsrot += 1.029f;
			juprot += 0.414;
			satrot += 0.448;
			urrot += 0.720;
			neprot += 0.674;
			
			
			mercorbit += 4.150f;
			venorbit += 1.630f;
			earthorbit += 1.000f;
			moonorbit +=9.791f;
			marsorbit += 0.532;
			juporbit += 0.084;
			satorbit += 0.032;
			urorbit += 0.012;
			neporbit += 0.006;
		}
        else{
			sunrot -= 0.040f;
			mercrot -= 0.170f;
			venrot -= 0.004f;
			earthrot -= 1.000f;
			moonrot -= 27.435f;
			marsrot -= 1.029f;
			juprot -= 0.414;
			satrot -= 0.448;
			urrot -= 0.720;
			neprot -= 0.674;
			
			mercorbit -= 4.150f;
			venorbit -= 1.630f;
			earthorbit -= 1.000f;
			moonorbit -=9.791f;
			marsorbit -= 0.532;
			juporbit -= 0.084;
			satorbit -= 0.032;
			urorbit -= 0.012;
			neporbit -= 0.006;
        }
	}
	
    if(sunrot > 360.0f)
		sunrot -= 360.0f;
	if(mercrot > 360.0f)
		mercrot -= 360.0f;
	if(venrot > 360.0f)
		venrot -= 360.0f;
    if(earthrot > 360.0f)
		earthrot -= 360.0f;
    if(moonrot > 360.0f)
		moonrot -=360.0f;
    if(marsrot > 360.0f)
		marsrot -=360.0f;
    if(juprot > 360.0f)
		juprot -=360.0f;
    if(satrot > 360.0f)
		satrot -=360.0f;
    if(urrot > 360.0f)
		urrot -=360.0f;
    if(neprot > 360.0f)
		neprot -=360.0f;
    
    if(mercorbit > 360.0f)
        mercorbit -= 360.f;
    if(venorbit > 360.0f)
        venorbit -= 360.f;
    if(earthorbit > 360.0f)
		earthorbit -= 360.0f;
    if(moonorbit > 360.0f)
		moonorbit -=360.0f;
    if(moonorbit > 360.0f)
		moonorbit -=360.0f;
    if(moonorbit > 360.0f)
		moonorbit -=360.0f;
    if(moonorbit > 360.0f)
		moonorbit -=360.0f;
    if(moonorbit > 360.0f)
		moonorbit -=360.0f;
    if(moonorbit > 360.0f)
		moonorbit -=360.0f;
	
    if(sunrot < 0.0f)
		sunrot += 360.0f;
	if(mercrot < 0.0f)
		mercrot += 360.0f;
	if(venrot < 0.0f)
		venrot += 360.0f;
    if(earthrot < 0.0f)
		earthrot += 360.0f;
    if(moonrot < 0.0f)
		moonrot +=360.0f;
    if(marsrot < 0.0f)
		marsrot +=360.0f;
    if(juprot < 0.0f)
		juprot +=360.0f;
    if(satrot < 0.0f)
		satrot +=360.0f;
    if(urrot < 0.0f)
		urrot +=360.0f;
    if(neprot < 0.0f)
		neprot +=360.0f;
	
    if(mercorbit < 0.0f)
        mercorbit += 360.f;
    if(venorbit < 0.0f)
        venorbit += 360.f;
    if(earthorbit < 0.0f)
		earthorbit += 360.0f;
	if(moonorbit < 0.0f)
		moonorbit +=360.0f;
	if(marsorbit < 0.0f)
		marsorbit +=360.0f;
	if(juporbit < 0.0f)
		juporbit +=360.0f;
	if(satorbit < 0.0f)
		satorbit +=360.0f;
	if(urorbit < 0.0f)
		urorbit +=360.0f;
	if(neporbit < 0.0f)
		neporbit +=360.0f;
	
	glutPostRedisplay();
	glutTimerFunc(TIMER, recomputeFrame, value);
}

// Default constructor
Render::Render() {
	// specify a default location for the camera
	eye[0] = 0.0f;
	eye[1] = 0.0f;
	eye[2] = 2000.0f;

	// specify default values to the rotational values in the transformation matrix
	rot[0] = 0.0f;
	rot[1] = 0.0f;
	rot[2] = 0.0f;

	LEFT = 0;
	MIDDLE = 1;
	RIGHT = 2;
	mButton = -1;
}

Render::~Render() {
}

void Render::init(void) {
	// clear the background to the color values specified in the parentheses
	glClearColor (0.0, 0.0, 0.0, 0.0);

	// this is a 3D scene. so, clear the depth
	glClearDepth(1.0);

	// I need depth. enable depth
	glEnable(GL_DEPTH_TEST);

	glShadeModel (GL_SMOOTH);

	glEnable(GL_LIGHTING);

    // setup ambient light
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
	glLightModelfv (GL_LIGHT_MODEL_AMBIENT, ambientColor);

    // setup positioned light
    GLfloat lightColor0[] = {0.4f, 0.4f, 0.2f,1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos0[] = {0.0f, 0.0f, 0.0f, 1.0f}; //Positioned (0, 0, 0). Last param indicates fixed positional light
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);

	recomputeFrame(0);
}

void Render::reshape(int w, int h) {
	glViewport(0,0,(GLsizei) w, (GLsizei) h);
	Wx = w;
	Wy = h;
}

void Render::mouseClick(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		mOldX = x;
		mOldY = y;
        switch (button) {
			case GLUT_LEFT_BUTTON:
				mButton = LEFT;
				break;
			case GLUT_MIDDLE_BUTTON: 
				mButton = MIDDLE; 
				break;
			case GLUT_RIGHT_BUTTON:
				mButton = RIGHT;
				break;
			default:
				break;
		}
	}
	else if (state == GLUT_UP) {
		mButton = -1;
	}
}

void Render::mouseMove(int x, int y) {
	if (mButton == LEFT) {
		rot[0] -= ((mOldY - y) * 180.0f) / 1000.0f;
		rot[1] -= ((mOldX - x) * 180.0f) / 1000.0f;
		clamp(rot[0], rot[1], rot[2]);
	}
	else if (mButton == MIDDLE) {
		eye[2] -= ((mOldY - y) * 180.0f) / 500.0f;
		clamp(rot[0], rot[1], rot[2]);
	}
	else if (mButton == RIGHT) {
		eye[0] += ((mOldX - x) * 180.0f) / 1000.0f;
		eye[1] -= ((mOldY - y) * 180.0f) / 1000.0f;
		clamp(rot[0], rot[1], rot[2]);
	}	 
	mOldX = x; 
	mOldY = y;

}

void Render::keyPos(unsigned char key, int x, int y) {
	switch (key) {
		default:
			break;
	case 'p':
		paused = !paused;
		break;
	case 'r':
		reversed = !reversed;

		//Code
		break;
	    case 27:	// this is for the 'Esc' key on the keyboard, quit the program when the esc key is pressed
			exit (0);
	}
}

void Render::display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Specifies which matrix stack is the target for subsequent matrix operations
	// In this example, the projection matrix is set to perspective projection matrix stack
	glMatrixMode(GL_PROJECTION);
	// all matrix values from previous frames set to identity
	glLoadIdentity();
	
	// perspective projection loaded with new values for Wx and Wy updated
	gluPerspective(45, (GLfloat) Wx/(GLfloat) Wy, 1.0, 10000.0);
	// use glOrtho for a 3D orthogonal projection
	//glOrtho(-100, 100, -100, 100, -100, 100);

	// Applies subsequent matrix operations to the modelview matrix stack.
	glMatrixMode(GL_MODELVIEW);
	// Clears all the previously loaded values in the modelview matrix
	glLoadIdentity();
	// Now, add a bunch of transformation operations
	glTranslatef(-eye[0], -eye[1], -eye[2]);
	glRotatef(rot[0], 1.0f, 0.0f, 0.0f);
	glRotatef(rot[1], 0.0f, 1.0f, 0.0f);
	glRotatef(rot[2], 0.0f, 0.0f, 1.0f);

	// draw objects
	drawPlanetarySystem();
	
	// this allows opengl to wait for the draw buffer to be ready in the background for the next frame
	// therefore, while the current buffer is being drawn in the current frame, a buffer is set ready to draw on frame+1
	// this call is effective only when GL_DOUBLE is enabled in glutInitDisplayMode in the main function
	// It is recommended to use glutSwapBuffers and double buffering always
	glutSwapBuffers();
}

void Render::drawPlanetarySystem(void) {
	drawSun();
	drawMercury();
	drawVenus();
	drawEarth();
	drawMoon();
	drawMars();
//	drawJupiter();
//	drawSaturn();
//	drawUranus();
//	drawNeptune();
}

void Render::drawSun(void) {
	glEnable(GL_LIGHT0);
    
	glColor3f(1.0, 1.0, 0.0);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	glPolygonMode(GL_BACK, GL_FILL);
    
	glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glRotatef(23.9*sunrot, 0, 0, 1);
    
//	GLfloat mat_emission[] = {0.5, 0.5, 0.3, 0.0};
//	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    gluSphere(qobj, 200, 15, 15);
    glPopMatrix();
    
    std::cout << "SOL\t\t| rotation: " << sunrot << "\n";
    
	glDisable(GL_LIGHT0);
}

void Render::drawMercury(void) {

    GLfloat lightColor1[] = {0.5f, 0.4f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    GLfloat lightPos1[] = {1.0f, 0.0f, 0.0f, 1.0f}; //Last parameter '0.0' indicates directional light

	glEnable(GL_LIGHT1);
    
	glColor3f(0.2, 0.5, 0.7);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	glPolygonMode(GL_BACK, GL_FILL);
    
	glPushMatrix();
    glRotatef(mercorbit, 0, 1, 0);
    
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    glTranslatef(1.5*257.9, 0, 0);
    glRotatef(mercorbit, 0, -1, 0);
    glRotatef(89.99, 1, 0, 0);
	glRotatef(239*mercrot, 0, 0, 1);

    gluSphere(qobj, 0.5*49, 15, 15);
    glPopMatrix();
    
    std::cout << "MERCURY\t| rotation: " << mercrot << "\t\t orbit: " << mercorbit << "\n";

    glDisable(GL_LIGHT1);
}

void Render::drawVenus(void) {

    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.4f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {1.0f, 0.0f, 0.0f, 1.0f}; //Last parameter '0.0' indicates directional light
    
	glEnable(GL_LIGHT1);
    
	glColor3f(0.0, 0.8, 0.8);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	glPolygonMode(GL_BACK, GL_FILL);
    
	glPushMatrix();
	glRotatef(venorbit, 0, 1, 0);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	glTranslatef(2*308.2, 0, 0);
	glRotatef(venorbit, 0, -1, 0);
	glRotatef(-87.4, 1, 0, 0);
	glRotatef(23.9*venrot, 0, 0, 1);

    gluSphere(qobj, 0.5*121, 15, 15);
    glPopMatrix();

    std::cout << "VENUS\t| rotation: " << venrot << "\t\t orbit: " << venorbit << "\n";

	glDisable(GL_LIGHT1);
}

void Render::drawEarth(void) {

    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.4f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {1.0f, 0.0f, 0.0f, 1.0f}; //Last parameter '0.0' indicates directional light
    
	glEnable(GL_LIGHT1);
    
	glColor3f(0.0, 0.6, 0.9);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	glPolygonMode(GL_BACK, GL_FILL);
    
	glPushMatrix();
	glRotatef(earthorbit, 0, 1, 0);
    
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	glTranslatef(2.5*349.6, 0, 0);
	glRotatef(earthorbit, 0, -1, 0);
	glRotatef(66.6, 1, 0, 0);
	glRotatef(23.9*earthrot, 0, 0, 1);
	
	gluSphere(qobj, 0.5*128, 15, 15);
    glPopMatrix();
	
    std::cout << "EARTH\t| rotation: " << earthrot << "\t\t\t orbit: " << earthorbit << "\n";

	glDisable(GL_LIGHT1);
}

void Render::drawMoon(void) {

    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.4f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {1.0f, 0.0f, 0.0f, 1.0f}; //Last parameter '0.0' indicates directional light
    
	glEnable(GL_LIGHT1);
    
	glColor3f(1.0, 1.0,	1.0);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	glPolygonMode(GL_BACK, GL_FILL);
	
    glPushMatrix();
	
	// Earth transformations
	glRotatef(earthorbit, 0, 1, 0);
    
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
		
	glTranslatef(2.5*349.6, 0, 0);
	glRotatef(earthorbit, 0, -1, 0);
	glRotatef(66.6, 1, 0, 0);
	
	// Moon transformations
	glRotatef(moonorbit, 0, 0, 1);
	glTranslatef(100, 0, 0);
	glRotatef(moonorbit, 0, 0, -1);
	glRotatef(-6.7, 1, 0, 0);
	glRotatef(23.9*moonrot, 0, 0, 1);
	
    gluSphere(qobj, 0.5*35, 15, 15);
	glPopMatrix();

	std::cout << "LUNA\t| rotation: " << moonrot << "\t\t orbit: " << moonorbit << "\n";

	glDisable(GL_LIGHT1);

}

void Render::drawMars(void) {
	
    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.4f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {1.0f, 0.0f, 0.0f, 1.0f}; //Last parameter '0.0' indicates directional light
    
	glEnable(GL_LIGHT1);
    
	glColor3f(0.0, 0.6, 0.9);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	glPolygonMode(GL_BACK, GL_FILL);
    
	glPushMatrix();
	glRotatef(marsorbit, 0, 1, 0);
    
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	glTranslatef(2.5*427.9, 0, 0);
	glRotatef(marsorbit, 0, -1, 0);
	glRotatef(64.8, 1, 0, 0);
	glRotatef(23.9*marsrot, 0, 0, 1);
	
	gluSphere(qobj, 0.5*68, 15, 15);
    glPopMatrix();
	
    std::cout << "MARS\t| rotation: " << marsrot << "\t\t\t orbit: " << marsorbit << "\n";
	
	glDisable(GL_LIGHT1);
}

void Render::drawJupiter(void) {
	
    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.4f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {1.0f, 0.0f, 0.0f, 1.0f}; //Last parameter '0.0' indicates directional light
    
	//    glEnable(GL_LIGHT1);
    
	glColor3f(0.0, 0.6, 0.9);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	//	glPolygonMode(GL_BACK, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
    
	glPushMatrix();
	glRotatef(juporbit, 0, 1, 0);
    
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	glTranslatef(2*778.6, 0, 0);
	glRotatef(juporbit, 0, -1, 0);
	glRotatef(86.9, 1, 0, 0);
	glRotatef(23.9*juprot, 0, 0, 1);
	
	gluSphere(qobj, 0.5*1430, 10, 10);
    glPopMatrix();
	
    std::cout << "JUPITER\t| rotation: " << juprot << "\t\t\t orbit: " << juporbit << "\n";
	
	//    glDisable(GL_LIGHT1);
}

void Render::drawSaturn(void) {
	
    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.4f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {1.0f, 0.0f, 0.0f, 1.0f}; //Last parameter '0.0' indicates directional light
    
	//    glEnable(GL_LIGHT1);
    
	glColor3f(0.0, 0.6, 0.9);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	//	glPolygonMode(GL_BACK, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
    
	glPushMatrix();
	glRotatef(satorbit, 0, 1, 0);
    
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	glTranslatef(2*1433.5, 0, 0);
	glRotatef(satorbit, 0, -1, 0);
	glRotatef(63.3, 1, 0, 0);
	glRotatef(23.9*satrot, 0, 0, 1);
	
	gluSphere(qobj, 0.5*1205, 10, 10);
    glPopMatrix();
	
    std::cout << "SATURN\t| rotation: " << satrot << "\t\t\t orbit: " << satorbit << "\n";
	
	//    glDisable(GL_LIGHT1);
}

void Render::drawUranus(void) {
	
    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.4f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {1.0f, 0.0f, 0.0f, 1.0f}; //Last parameter '0.0' indicates directional light
    
	//    glEnable(GL_LIGHT1);
    
	glColor3f(0.0, 0.6, 0.9);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	//	glPolygonMode(GL_BACK, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
    
	glPushMatrix();
	glRotatef(urorbit, 0, 1, 0);
    
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	glTranslatef(2*2872.5, 0, 0);
	glRotatef(urorbit, 0, -1, 0);
	glRotatef(-7.8, 1, 0, 0);
	glRotatef(23.9*urrot, 0, 0, 1);
	
	gluSphere(qobj, 0.5*511, 10, 10);
    glPopMatrix();
	
    std::cout << "URANUS\t| rotation: " << urrot << "\t\t\t orbit: " << urorbit << "\n";
	
	//    glDisable(GL_LIGHT1);
}

void Render::drawNeptune(void) {
	
    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.4f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {1.0f, 0.0f, 0.0f, 1.0f}; //Last parameter '0.0' indicates directional light
    
	//    glEnable(GL_LIGHT1);
    
	glColor3f(0.0, 0.6, 0.9);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	//	glPolygonMode(GL_BACK, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
    
	glPushMatrix();
	glRotatef(neporbit, 0, 1, 0);
    
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	glTranslatef(2*4495.1, 0, 0);
	glRotatef(neporbit, 0, -1, 0);
	glRotatef(61.7, 1, 0, 0);
	glRotatef(23.9*neprot, 0, 0, 1);
	
	gluSphere(qobj, 0.5*495, 10, 10);
    glPopMatrix();
	
    std::cout << "NEPTUNE\t| rotation: " << neprot << "\t\t\t orbit: " << neporbit << "\n";
	
	//    glDisable(GL_LIGHT1);
}

// this is for clamping the numbers between 0 & 360. used for rotation values in the mouse move function
void Render::clamp(float v0, float v1, float v2) {
	if (v0 > 360 || v0 < -360)
		v0 = 0;
	if (v1 > 360 || v1 < -360)
		v1 = 0;
	if (v2 > 360 || v2 < -360)
		v2 = 0;
}


