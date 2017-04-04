#include <bits/stdc++.h>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

int X1, X2, Y1, Y2;

void drawLine() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	int dx, dy, x, y, incE, incNE, decision;

	dx = X2 - X1;
	dx = abs(dx);

	dy = Y2 - Y1;
	dy = abs(dy);

	if(dy > dx) {
		incE = 2*dx;
		incNE = 2*dx - 2*dy;

		decision = 2*dy - dx;

		x = X1;
		y = Y1;

		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_POINTS);
			glVertex2d(x*0.01f, y*0.01f);

			do {
				if(decision <= 0)
					decision += incE;
				else {
					decision += incNE;
					x += 1;
				}

				y += 1;
				glVertex2d(x*0.01f, y*0.01f);
			}while(y!=Y2);

		glEnd();
		glFlush();
	}
	else {
		incE = 2*dy;
		incNE = 2*dy - 2*dx;

		decision = 2*dx - dy;

		x = X1;
		y = Y1;

		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_POINTS);
			glVertex2d(x*0.01f, y*0.01f);

			do {
				if(decision <= 0)
					decision += incE;
				else {
					decision += incNE;
					y += 1;
				}
				x += 1;
				glVertex2d(x*0.01f, y*0.01f);
			}while(x != Y2);

		glEnd();
	}

}


void Init() {
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(0,640,0,480);
}

int main(int argc, char **argv) {

	scanf("%d %d",&X1,&X2);

	scanf("%d %d",&X2,&Y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 600);

	glutCreateWindow("Midpoint Line Drawing Algorithm");

	// init();

	glutDisplayFunc(drawLine);
	glutMainLoop();
}