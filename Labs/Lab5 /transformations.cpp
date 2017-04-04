#include <bits/stdc++.h>
#include "GL/freeglut.h"
#include "GL/gl.h"

void renderTrans() {
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.5f, 1.0f);
		glVertex2f(0.3f, 0.2f);
		// glTranslatef(0.5f, -0.1f, 0.0f);
		// glRotatef(90, 1.0, 0.0, 0.0);
	glEnd();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {

	if(key == 27)
		exit(0);
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1080, 680);

	glutCreateWindow("Transformations");

	glutDisplayFunc(renderTrans);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}