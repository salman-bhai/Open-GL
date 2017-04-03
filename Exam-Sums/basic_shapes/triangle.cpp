#include "GL/freeglut.h"
#include "GL/gl.h"

void renderAnimation() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 1.0f, 1.0f);
		//Order is important
		glVertex2f(0.0f, 0.0f);	//Left Bottom  
		glVertex2f(1.0f, 0.0f);
		glVertex2f(0.0f, 1.0f);
	glEnd();

	glFlush();
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);

	glutCreateWindow("Open GL Triangle");

	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowSize(750, 750);
	glutInitWindowPosition(150, 150);

	glutDisplayFunc(renderAnimation);
	glutMainLoop();

	return 0;
}