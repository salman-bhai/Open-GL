#include "GL/freeglut.h"
#include "GL/gl.h"

void renderTriangle() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.5f, 0.0f);
		glVertex2f(0.5f, 0.0f);
		glVertex2f(0.0f, 1.0f);
	glEnd();

	glFlush();
}

void multiColorTriangle() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.5f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.5f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, 1.0f);
	glEnd();

	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Open GL - Triangle");

	glutDisplayFunc(multiColorTriangle);
	glutMainLoop();

	return 0;
} 