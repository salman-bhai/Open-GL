#include <bits/stdc++.h>
#include "GL/freeglut.h"
#include "GL/gl.h"

void draw() {
	glClearColor(100, 100, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 20.0, 0.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(4, 2, 0);
	glColor3f(1, 0, 0);

	glBegin(GL_LINES);
		glVertex2f(5.0,1.5);
		glVertex2f(5.3,7.4);
	glEnd();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	if(key == 27)
		exit(0);
}

int main(int argc, char ** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Transformation in Open GL");

	glutDisplayFunc(draw);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}