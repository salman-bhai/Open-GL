#include <bits/stdc++.h>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

double X1, X2, Y1, Y2;

void lineRenderer() {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	double dx = X2 - X1;
	double dy = Y2 - Y1;
	double steps;

	if(abs(dx) > abs(dy)) 
		steps = abs(dx);
	else
		steps = abs(dy);

	float xInc, yInc;
	float x = X1;
	float y = Y1;

	xInc = dx/(float)steps;
	yInc = dy/(float)steps;

	glBegin(GL_POINTS);
		glVertex2d(x*0.01f, y*0.01f);

		for(int k = 0; k < steps; k ++) {
			x += xInc;
			y += yInc;

			glVertex2d(x*0.01f, y*0.01f);
		}
	glEnd();

	glFlush();
}

int main(int argc, char **argv) {
	
	scanf("%lf %lf",&X1,&Y1);

	scanf("%lf %lf",&X2,&Y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 750);

	glutCreateWindow("DDA Line Drawing Algorithm");

	glutDisplayFunc(lineRenderer);
	glutMainLoop();

	return 0;
}