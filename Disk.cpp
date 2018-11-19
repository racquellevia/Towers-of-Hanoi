// ITP 365 Fall 2017
// HW3 Towers of Hannoi
// Name: Racquel Fygenson
// Email: rfygenso@usc.edu
// Platform: Mac

#include <stdio.h>
#include "Disk.h"


Disk::Disk()
{
    //default constructor
    mX = 0;
    mY = 0;
    mHeight = 0;
    mWidth = 0;
    mColor ="BLUE";
}


Disk::Disk(int x, int y, int width, int height)
{
    //set all the memberVars of the disk
    mX = x;
    mY = y;
    mHeight = height;
    mWidth = width;
    mColor ="BLUE";
    
   
}


void Disk::setX(int x)
{
    //set just the x coordinate of the disk
    mX = x;
}

void Disk::setY(int y)
{
    //set just the y coordinate of the disk
    mY = y;
}

int Disk::getHeight()
{
    return mHeight;
}

void Disk::draw(GWindow& gw)
{
    //draw a rectangle using the memberVars as parameters
    gw.setColor(mColor);
    gw.fillRect(mX-(mWidth/2), mY-mHeight, mWidth, mHeight); //set the x,y input to be @ bottom center of disk
}
