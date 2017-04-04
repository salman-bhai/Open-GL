#include <stdio.h>
#include <math.h>
#include "GL/freeglut.h"
#include "GL/gl.h"

double X1,Y1,X2,Y2;

float round_value(float v) {
    return floor(v+0.5);
    
}

void LineDDA(void) {
    
    double dx = X2-X1;
    double dy = Y2-Y1;
    double steps;
    
    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else
        steps=abs(dy);
    
    float xInc,yInc;
    float x=X1;
    float y=Y1;
    
    xInc=dx/(float)steps;
    yInc=dy/(float)steps;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,1,1);

    glBegin(GL_POINTS);
    glVertex2d(x,y);
    
    int k;
    for(k=0;k<steps;k++) {
        x+=xInc;
        y+=yInc;

        glVertex2d(round_value(x),round_value(y));
    }
    glEnd();

    glFlush();
}

void Init() {
    glClearColor(0.0,0.0,1.0,0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(0,640,0,480);
}

int main(int argc, char *argv[]) {
    
    printf("Enter two end points of the line to be drawn\n");
    printf("\nEnter Point 1(X1,Y1): ");
    
    scanf("%lf %lf",&X1,&Y1);
    
    printf("\nEnter Point 2(X2,Y2): ");
    scanf("%lf %lf",&X2,&Y2);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    
    glutInitWindowPosition(0,0);
    glutInitWindowSize(600,480);
    
    glutCreateWindow("DDA Line Drawing Algorithm");
    Init();
    
    glutDisplayFunc(LineDDA);
    glutMainLoop();

    return EXIT_SUCCESS;
}

