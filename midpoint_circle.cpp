#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int R;

void Init() {
  glClearColor(1.0,1.0,0.0,1.0);
  glColor3f(1.0,0.0,0.0);
  gluOrtho2D(0,640,0,480);
}

void putpixel(int x,int y) {
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}

void drawCircle() {
  int h,x,y,decision;
  x=0;
  y=R;
  decision=1-R;
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
           //glVertex2d(x,y);
  while(x<=y) {
    putpixel(250+x,250+y);
    putpixel(250+y,250+x);
    putpixel(250-x,250+y);
    putpixel(250-y,250+x);
    putpixel(250+y,250-x);
    putpixel(250+x,250-y);
    putpixel(250-x,250-y);
    putpixel(250-y,250-x);

    if(decision<0) {
      decision+=2*x+3;
    }
    else {
      decision+=2*x-2*y+5;
      y=y-1;
    }
    x+=1;
    //glVertex2d(x,y);
  }
  glEnd();
  glFlush();
}

int main(int argc,char** argv) {
  printf("enter the radius of the circle\n");
  scanf("%d",&R);
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  glutCreateWindow("midpoint circle drawing");
  Init();
  glutDisplayFunc(drawCircle);
  glutMainLoop();
  return 0;
}
