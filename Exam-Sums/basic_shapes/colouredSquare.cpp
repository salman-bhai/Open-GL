#include "GL/freeglut.h"
#include "GL/gl.h"

void renderSquare() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
		//Initialise colour
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.5f, -0.5f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.5f, -0.5f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.5f, 0.5f);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex2f(-0.5f, 0.5f);
	glEnd();

	glFlush();
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);

	glutCreateWindow("Squares in Open GL");

	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowSize(750 ,750);
	glutInitWindowPosition(150, 150);

	glutDisplayFunc(renderSquare);
	glutMainLoop();

	return 0;
}