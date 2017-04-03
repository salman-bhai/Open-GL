#include "GL/freeglut.h"
#include "GL/gl.h"

void renderPolygon() {
	//Optional but if not done default colour is black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-1.0f, 0.0f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
	glEnd();

	glFlush();
}

int main(int argc, char **argv) {
	/* code */
	glutInit(&argc, argv);

	glutCreateWindow("Polygons in Open GL");

	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowSize(1000, 750);
	glutInitWindowPosition(150, 150);

	glutDisplayFunc(renderPolygon);
	glutMainLoop();

	return 0;
}