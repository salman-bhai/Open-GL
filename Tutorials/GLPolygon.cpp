#include "GL/gl.h"
#include "GL/freeglut.h"

void drawPolygon() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.f5, 0.75f);
		glVertex2f(-0.5f, -0.5f);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(0.5f, -0.5f);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.5f, 0.5f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.5f, 0.5f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-1.0f, 0.0f);
	glEnd();

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(1000, 750);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Open GL Polygon");
	glutInitDisplayMode(GLUT_SINGLE);

	glutDisplayFunc(drawPolygon);
	glutMainLoop();
}