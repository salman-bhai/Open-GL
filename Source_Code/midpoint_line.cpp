#include <stdio.h>
#include <math.h>
#include "GL/freeglut.h"
#include "GL/gl.h"

int X1,X2,Y1,Y2;

void drawLine() {
    int dx,dy,x,y,incE,incNE,decision;
  
    dx=X2-X1;
    dy=Y2-Y1;
    dx=abs(dx);
    dy=abs(dy);

    if(dy>dx) {
        incE=2*dx;
        incNE=2*dx-2*dy;
        
        decision=2*dy-dx;
        
        x=X1;
        y=Y1;
        
        glClear(GL_COLOR_BUFFER_BIT);
        //glColor3f(0.0,0.0,0.0);
        glBegin(GL_POINTS);
        glVertex2d(x,y);
        
        do {
            if(decision<=0)
                decision+=incE;
            else {
                decision+=incNE;
                x+=1;
            }
        
            y+=1;
            glVertex2d(x,y);

        }while(y!=Y2);

        glEnd();
        glFlush();
    }

    else {
        incE=2*dy;
        incNE=2*dy-2*dx;
        decision=2*dy-dx;
        x=X1;
        y=Y1;
        glClear(GL_COLOR_BUFFER_BIT);
        // glColor3f(0.0,0.0,0.0);
        glBegin(GL_POINTS);
        glVertex2d(x,y);
        do {
            if(decision<=0)
                decision+=incE;
            else {
                decision+=incNE;
                y+=1;
            }
            x+=1;
            glVertex2d(x,y);
        }while(x!=X2);

        glEnd();
        glFlush();
    }
}

void Init() {
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(0,640,0,480);
}

int main(int argc,char* argv[]) {

    printf("Enter two end points of the line\n");
    
    printf("Enter x1 and y1\n");
    scanf("%d%d",&X1,&Y1);
    
    printf("Enter x2 and y2\n");
    scanf("%d%d",&X2,&Y2);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    
    glutCreateWindow("Midpoint Line Drawing Algorithm");
    Init();
    glutDisplayFunc(drawLine);
    glutMainLoop();

    return EXIT_SUCCESS;
}
