#include <bits/stdc++.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
// Header file for GLUT and OpenGL
// DRAWING CALLBACK FUNCTION
void draw(){
// background colour: yellow
	glClearColor( 100, 100, 0, 0 );
	glClear ( GL_COLOR_BUFFER_BIT );
// Sets up the DOMAIN (xmin,xmax,ymin,ymax) in R2.
// Let (xmin,xmax,ymin,ymax)=(0.0,20.0,0.0,20.0)
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,20.0,0.0,20.0);
// Let us now define the line segment in red
// Endpoints: (5.0,1.5) and (9.3,7.2)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(5,-2,0);
	glColor3f( 1, 0, 0 );
	glBegin(GL_LINES);
		glVertex2f(5.0,1.5);
		glVertex2f(9.3,7.2);
	glEnd();
// display line segment
	glutSwapBuffers();
}// KEYBOARD CALLBACK FUNCTION

void keyboard(unsigned char key,int x,int y) {
// press ESC key to quit
	if(key==27) exit(0);
}
//--------------------------------------------------------------
// MAIN FUNCTION
//--------------------------------------------------------------
int main(int argc, char ** argv) {
	glutInit(&argc, argv);
// Double Buffered RGB display
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE);
// Set window size
	glutInitWindowSize( 500,500 );
	glutCreateWindow("Line Segment");
// Declare callback functions
	glutDisplayFunc(draw);
	glutKeyboardFunc(keyboard);
// Start the main loop of events
	glutMainLoop();
	return 0;
}