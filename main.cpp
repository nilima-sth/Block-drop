#include<windows.h>
#include<GL/gl.h>
#include <GL/glu.h>
#include<GL/glut.h>
#include <ctime>
#include<stdlib.h>
#include <stdio.h>   //C
#include <iostream>  //C++
#include <string>
#include "hamrogame.h"

#define COLUMNS 30
#define ROWS 40
#define fps 5 //speed

int state=1;  //tala khasney
int pstate=1;
int xc=COLUMNS/2,yc=ROWS/2;
int width=700,height=700;
int start=0;

extern int score;
extern bool food;
extern bool bonus;


extern int posX,posY;
extern int eatX,eatY;
extern int pX,pY;
bool endgame = false;
bool gameOverMessageDisplayed=false;
extern short sDirec;

void presseddd_key(int,int,int);
void timer(int);

void MyInit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    initGrid(COLUMNS,ROWS);
}

void reshape(int w, int h){
glViewport(0,0,(GLsizei)w,(GLsizei)h);
//projection
glMatrixMode(GL_PROJECTION);
glLoadIdentity();   //resets p
glOrtho(0,COLUMNS,0,ROWS,-1.0,1.0);   //lrbt
glMatrixMode(GL_MODELVIEW);
}
void restart()
{
    endgame=false;
    score=0;
    food=true;
    bonus=true;
    posX = posY = 3;
    sDirec = LOCK;
}
//1st page setup
void process_key(unsigned char key,int x,int y)
{
    switch(key){
case ' ':
    if(start == 0){
        start = 1;
    }
    break;
case 27:
    exit(0);
    break;
case 'r':
case'R':
   restart();
    break;

default:
    break;
}
}

void timer(int n)
{
    glutPostRedisplay(); //display function is called,
    glutTimerFunc(1000/fps,timer,0);

        pY -= 1;
   if(eatY >= 2 ){
        eatY -= 1;
    }
    else if(eatY == 1)
    {
        endgame = true;
    }
}

void presseddd_key(int key,int x,int y)
{
switch(key)
{
case GLUT_KEY_UP :
        sDirec = UP;
    break;
case GLUT_KEY_DOWN:

        sDirec = DOWN;
    break;
case GLUT_KEY_LEFT:

        sDirec = LEFT;

    break;
case GLUT_KEY_RIGHT:

        sDirec = RIGHT;
            break;
case GLUT_KEY_PAGE_UP:

    sDirec = LOCK;
    break;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    bkcolor();
    drawGrid();
    drawBlock();
    drawEat(); //red
    EATEat();  //yellow

    glFlush();
    glutSwapBuffers();

    if(endgame && !gameOverMessageDisplayed)
    {
        gameOverMessageDisplayed=true;
        char text[80]="Press Ok to Restart\nYour Score is ";
        char _score[50];
        itoa(score,_score,10);
        strcat(text,_score);
        MessageBox( NULL,text,"GAME OVER",0);
        restart();
        gameOverMessageDisplayed=false;
    }

}

int main(int argC,char **argV)
{
    glutInit(&argC, argV);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(250,20);
    glutCreateWindow("Block Drop");

    glutReshapeFunc(reshape);

    glutDisplayFunc(display);

    glutKeyboardFunc(process_key);
    glutTimerFunc(0,timer,0); //delay,fxn,pss garne value
    glutSpecialFunc(presseddd_key);


    MyInit();
    glutMainLoop();
    return 0;
}
