#include<windows.h>
#include<GL/gl.h>
#include <ctime>
#include <math.h>
#include<GL/glut.h>
#include <GL/glu.h>
#include "hamrogame.h" //has constants

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void clouds()
{
    GLfloat r=1.5,x=5,y=35;

   // 1st cloud
    glColor3ub(255, 255, 255);circle(r*1.2, r*0.8, x+2, y-2);circle(r*1.2, r*0.8, x, y-3);circle(r*1.4, r, x-1, y-1);
   // 2nd cloud
    glColor3ub(255, 255, 255);circle(r*1.4, r*0.9, x+13, y-2);circle(r*1.3, r*0.9, x+10, y-2);circle(r*1.2, r, x+12, y-1);
    //3rd Cloud
    glColor3ub(254, 252, 255);circle(r*1.2, r*0.9, x+19+10, y-2);circle(r*1.3, r*0.9, x+1+15, y-2);circle(r*1.2, r*1.2, x+11+19, y-2.6);
    //4th Cloud
    glColor3ub(254, 252, 255);circle(r * 1.2, r * 0.9, x + 10, y - 10);circle(r * 1.3, r * 0.9, x +6, y - 10);circle(r * 1.2, r * 1.2, x+8, y - 11);



}

void bkcolor(){
    glClear(GL_COLOR_BUFFER_BIT);
    //sky
    glBegin(GL_POLYGON);
    glColor3f(0.000, 0.749, 1.000);glVertex2f(0,40);
    glColor3f(0.000, 0.749, 1.000);glVertex2f(0,20);
    glColor3f(0.686, 0.933, 0.933);glVertex2f(40,20);
    glColor3f(0.686, 0.933, 0.933);glVertex2f(40,40);
    glEnd();

    clouds();

glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.3);glVertex2f(0,20);
glColor3f(0.5,0.5,0.3);glVertex2f(0,15);
glColor3f(0.5,0.5,0.3);glVertex2f(40,15);
glColor3f(0.5,0.5,0.3);glVertex2f(40,20);
glEnd();

//grass
glBegin(GL_POLYGON);
glColor3f(0.0,0.95,0.0);glVertex2f(0,15);
glColor3f(0.5,1.0,0.0);glVertex2f(0,0);
glColor3f(0.5,0.9,0.0);glVertex2f(40,0);
glColor3f(0.0,1.0,0.0);glVertex2f(40,15);
glEnd();
}

