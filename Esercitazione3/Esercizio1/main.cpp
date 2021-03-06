/**
 * @file		main.cpp
 * @brief	Slightly more complex FreeGLUT usage example
 *
 * @author	Achille Peternier (C) SUPSI [achille.peternier@supsi.ch]
 */



 //////////////
 // #INCLUDE //
 //////////////

	// GLM:
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// FreeGLUT:   
#include <GL/freeglut.h>

// C/C++:
#include <iostream>      



/////////////
// GLOBALS //
/////////////

   // Rotation angle:
float angle = 10.0f;
float distance = -45.0f;
int windowId;

bool spacePressed = false;
bool changeColor = false;



///////////////
// CALLBACKS //
///////////////


void drawCube(float dimension)
{
	float r = ((float)(rand() % 10)) / 9.0f;
	float g = ((float)(rand() % 10)) / 9.0f;
	float b = ((float)(rand() % 10)) / 9.0f;

	//float color = ((float)(rand() % 10)) / 9.0f;

	glBegin(GL_TRIANGLE_STRIP);

	//glColor3f(0.0f, 0.0f, 1.0f);


	if (changeColor)
	{
		glColor3f(r, g, b);
		changeColor = false;
	}

	glVertex3f(-10.0f, -10.0f, 10.0f);
	glVertex3f(10.0f, -10.0f, 10.0f);
	glVertex3f(-10.0f, 10.0f, 10.0f);
	glVertex3f(10.0f, 10.0f, 10.0f);

	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-10.0f, 10.0f, -10.0f);
	glVertex3f(10.0f, 10.0f, -10.0f);

	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-10.0f, -10.0f, -10.0f);
	glVertex3f(10.0f, -10.0f, -10.0f);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	//glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3f(-10.0f, 10.0f, 10.0f);
	glVertex3f(-10.0f, 10.0f, -10.0f);
	glVertex3f(-10.0f, -10.0f, 10.0f);
	glVertex3f(-10.0f, -10.0f, -10.0f);

	//glColor3f(0.5f, 1.0f, 1.0f);
	glVertex3f(10.0f, -10.0f, 10.0f);
	glVertex3f(10.0f, -10.0f, -10.0f);

	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(10.0f, 10.0f, 10.0f);
	glVertex3f(10.0f, 10.0f, -10.0f);

	glEnd();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * This is the main rendering routine automatically invoked by FreeGLUT.
 */
void displayCallback()
{
	// Clear the screen:         
	glClearColor(1.0f, 0.6f, 0.1f, 1.0f); // RGBA components
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glClearDepth(float);

	// Set a matrix to move our triangle: 
	glm::mat4 translation = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, distance));
	glm::mat4 rotationZ = glm::rotate(glm::mat4(), glm::radians(angle), glm::vec3(1.0f, 1.0f, 0.0f));

	// Compute model matrix:
	glm::mat4 f = translation * rotationZ;

	// Set model matrix as current OpenGL matrix:
	glLoadMatrixf(glm::value_ptr(f));

	// Pass a triangle (object coordinates: the triangle is centered around the origin):    
	drawCube(10.0f);

	if(!spacePressed)
		angle += 0.1f;

	// Swap this context's buffer:     
	glutSwapBuffers();
	glutPostWindowRedisplay(windowId);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * This callback is invoked each time the window gets resized (and once also when created).
 * @param width new window width
 * @param height new window height
 */
void reshapeCallback(int width, int height)
{
	std::cout << "[reshape func invoked]" << std::endl;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 1.0f, 100.0f);
	glLoadMatrixf(glm::value_ptr(projection));
	glMatrixMode(GL_MODELVIEW);

	//glutPostWindowRedisplay(windowId);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * This callback is invoked each time a special keyboard key is pressed.
 * @param key key pressed id
 * @param mouseX mouse X coordinate
 * @param mouseY mouse Y coordinate
 */
void specialCallback(int key, int mouseX, int mouseY)
{
	std::cout << "[key pressed]" << std::endl;

	const float speed = 0.5f;
	switch (key)
	{
	case GLUT_KEY_UP:
		distance -= speed;
		break;

	case GLUT_KEY_DOWN:
		distance += speed;
		break;

	case GLUT_KEY_LEFT:
		angle += speed;
		break;

	case GLUT_KEY_RIGHT:
		angle -= speed;
		break;
	}

	//Force rendering refresh:
	glutPostWindowRedisplay(windowId);
}

void keyboardCallback(unsigned char key, int x, int y)
{
	switch (key)
	{
	case ' ':
		spacePressed = !spacePressed;
		break;
	case 'r':
		changeColor = true;
		glutPostWindowRedisplay(windowId);
		//drawCube(10.0f);
		break;
	}

	
}



//////////
// MAIN //
//////////

/**
 * Application entry point.
 * @param argc number of command-line arguments passed
 * @param argv array containing up to argc passed arguments
 * @return error code (0 on success, error code otherwise)
 */
int main(int argc, char *argv[])
{
	// Credits:
	std::cout << "Advanced FreeGLUT example - A. Peternier (C) SUPSI" << std::endl;
	std::cout << std::endl;

	// Init context:
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);

	// FreeGLUT can parse command-line params, in case:
	glutInit(&argc, argv);

	// Set some optional flags:
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	// Create the window with a specific title:   
	windowId = glutCreateWindow("FreeGLUT advanced example");

	glEnable(GL_DEPTH_TEST);

	// The OpenGL context is now initialized...

	// Set callback functions:
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutSpecialFunc(specialCallback);
	glutKeyboardFunc(keyboardCallback);

	// Check OpenGL version:
	std::cout << "OpenGL context" << std::endl;
	std::cout << "   version  . . : " << glGetString(GL_VERSION) << std::endl;
	std::cout << "   vendor . . . : " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "   renderer . . : " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "   extensions . : " << glGetString(GL_EXTENSIONS) << std::endl;

	// Additional context info:
	std::cout << "   color bit  . : " << glutGet(GLUT_WINDOW_BUFFER_SIZE)
		<< " (red: " << glutGet(GLUT_WINDOW_RED_SIZE)
		<< ", green: " << glutGet(GLUT_WINDOW_GREEN_SIZE)
		<< ", blue: " << glutGet(GLUT_WINDOW_BLUE_SIZE)
		<< ", alpha: " << glutGet(GLUT_WINDOW_ALPHA_SIZE)
		<< ")" << std::endl;
	int bits = 0;
	glGetIntegerv(GL_DEPTH_BITS, &bits);
	std::cout << "   depth bit  . : " << glutGet(GLUT_WINDOW_DEPTH_SIZE) << " (max " << bits << ")" << std::endl;
	std::cout << "   stencil bit  : " << glutGet(GLUT_WINDOW_STENCIL_SIZE) << std::endl;
	std::cout << "   double buff. : " << glutGet(GLUT_WINDOW_DOUBLEBUFFER) << std::endl;

	// Enter the main FreeGLUT processing loop:     
	glutMainLoop();

	// Done:
	std::cout << "[application terminated]" << std::endl;
	return 0;
}