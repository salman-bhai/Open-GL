#include "GL/freeglut.h"
#include "GL/gl.h"
	
void renderAnimation() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);



	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);

	glutCreateWindow("Mid Point Algorithm");
	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowSize(750, 750);
	glutInitWindowPosition(150, 150);

	glutDisplayFunc(renderAnimation);
	glutMainLoop();

	return 0;
}