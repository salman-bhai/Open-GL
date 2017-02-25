#include "GL/freeglut.h"
#include "GL/gl.h"

void renderAnimation() {
	//Optional, if done then default value is black 
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		//Order is important!!
		glVertex2f(-0.5f, -0.5f);	//Left Bottom
		glVertex2f(0.5f, -0.5f);	//Right Bottom
		glVertex2f(0.5f, 0.5f);		//Right Top
		glVertex2f(-0.5f, 0.5f);	//Left Top
	glEnd();

	glFlush();
}

int main(int argc, char** argv) {
	
	glutInit(&argc, argv);

	glutCreateWindow("OpenGL Tutorial Window");

	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowSize(750, 750);
	glutInitWindowPosition(150, 150);

	glutDisplayFunc(renderAnimation);
	glutMainLoop();

	return 0;
}