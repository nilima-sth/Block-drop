#include<windows.h>
#include<GL/gl.h>
#include <ctime>
#include<GL/glut.h>
#include <GL/glu.h>
#include "hamrogame.h" //has constants
#include "hamrogame.h" //has constants

int score =0;

int posX=5,posY=5; //position
int gridX,gridY; //maximum coordinates
int eatX,eatY;
int pX,pY;
extern bool endgame;

bool food = true;
bool bonus = true;

short sDirec = LOCK;

//grid
void initGrid(int x,int y)
{
    gridX=x;
    gridY=y;
}

void drawGrid()
{
    for(int x=0; x < gridX; x++)
    {
        for(int y=0; y<gridY;y++)
        {
            unit(x,y);
        }
    }
}

void unit(int x,int y)
{
    //for food
    if(  y == gridY-20 || y == gridY-1 )
    {
        glLineWidth(1.0);
        glColor3f(0.5,0.57,1.0);
    }
    else if( y == gridY-25 || y == gridY-1)
         {
        glLineWidth(1.0);
        glColor3f(0.0,0.0,0.0);
    }
    //red boundary for snake
   else if( x==0 || y == 0 || x == gridX-1 || y == gridY-25)
    {
       glLineWidth(1.0);
       glColor3f(1.0,0.0,0.0);
    }
    else if(x == 1 || y == 1 || x == 39 || y == 14) {
      glLineWidth(1.0);
      glColor3f(1.0,1.0,0.5); //color of grid
    }
    glBegin(GL_LINE_LOOP);
        glVertex2f(x,y);
        glVertex2f(x+1,y);
        glVertex2f(x+1,y+1);
        glVertex2f(x,y+1);
    glEnd();
}

void drawBlock()
{
    if(sDirec == UP)
    {
        posY += 1;
    }
    else if(sDirec == DOWN)
    {
        posY-= 1;
    }
    else if(sDirec == RIGHT)
    {
        posX+= 1;
    }
    else if(sDirec == LEFT)
    {
        posX -= 1;
    }
    else if(sDirec == LOCK)
    {
        posX = posX;
        posY = posY;
    }
     glColor3f(1,0.5,1.0);
     glRectd(posX,posY,posX+1,posY+1); //size of snake

     if(posX == 1 || posY == 1 || posX == gridX-1 || posY == 15 )
     {
        endgame = true;
     }
    if(posX == eatX && posY == eatY)
    {
        food = true;
        score++;
    }
    if(posX == pX && posY == pY)
    {
       bonus = true;
        score = score+2;
    }
    if(pX == 1 || pY == 1 || pX == gridX-1 )
     {
        bonus=true;
     }
}

void EATEat()
{

    if(bonus)
        random1(pX,pY);
        glColor3f(1.0,1.0,0.0);//yellow color
    glRectf(pX,pY,pX+1,pY+1);
bonus = false;

}
void drawEat()
{
//red food
if(food)
    random2(eatX,eatY);
glColor3f(1.0,0.0,0.0);
glRectf(eatX,eatY,eatX+1,eatY+1);
food = false;
}

void random1(int &x,int &y)
{
    int maxX = gridX-2;
    int minX = 2;
    int maxY = gridY-1;
    int minY = gridY-6;
 srand(time(NULL));
 //range
 x = minX + rand() % (maxX - minX+1);
 y = minY + rand() % (maxY - minY+1);
}

void random2(int &x,int &y)
{
    int maxX = gridX-2;
    int minX = 2;
    int maxY = gridY-1;
    int minY = gridY-6;
 srand(time(NULL));
 //range
 x = minX + rand() % (maxX - minX);
 y = minY + rand() % (maxY - minY);
}

