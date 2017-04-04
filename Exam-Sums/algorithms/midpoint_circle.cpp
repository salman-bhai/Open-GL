#include <bits/stdc++.h>
#include "GL/freeglut.h"
#include "GL/gl.h"

int R;

void Init() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	gluOrtho2D(0, 640, 0, 480);
}

void putPixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2f(x*0.01f, y*0.01f);
	glEnd();
	glFlush();
}

void drawCircle() {
	int h, x, y, decision;

	x = 0;
	y = R;
	decision = 1 - R;

	glClear(GL_COLOR_BUFFER_BIT);
	// glBegin(GL_POINTS);

	while(x <= y) {
		putPixel(0 + x, 0 + y);
		putPixel(0 + x, 0 - y);
		putPixel(0 + y, 0 + x);
		putPixel(0 + y, 0 - x);
		
		putPixel(0 - x, 0 - y);
		putPixel(0 - x, 0 + y);
		putPixel(0 - y, 0 - x);
		putPixel(0 - y, 0 + x);
		
		if(decision < 0) {
			decision += 2*x + 3;
		}
		else {
			decision += 2*x - 2*y + 5;
			y = y - 1;
		}
		x += 1;
	}
	glEnd();
	glFlush();
}

int main(int argc, char **argv) {
	scanf("%d",&R);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(0,0);
	glutInitWindowSize(640, 480);

	glutCreateWindow("Midpoint Circle drawing Algorithm");

	glutDisplayFunc(drawCircle);
	glutMainLoop();

	return 0;
} 