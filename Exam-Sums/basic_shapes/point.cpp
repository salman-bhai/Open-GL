#include "GL/freeglut.h"
#include "GL/gl.h"

void renderLines() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
		for(int i = 0; i < 10; i ++) {
			glVertex2f(0.1f*i, 0.5f);
		}
	glEnd();

	glBegin(GL_LINES);

		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
	glEnd();
	
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500 , 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Lines and Points");

	glutDisplayFunc(renderLines);
	glutMainLoop();

}