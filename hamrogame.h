#ifndef HAMROGAME_H_INCLUDED
#define HAMROGAME_H_INCLUDED

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define LOCK 3

void initGrid(int ,int );
void drawGrid();
void unit(int,int);

void drawBlock();
void drawEat();
void random1(int&, int&);
void random2(int&, int&);
void EATEat();

void bkcolor();
void circle(GLfloat,GLfloat,GLfloat,GLfloat);
void clouds();

#endif
