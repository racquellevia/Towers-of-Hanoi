// ITP 365 Fall 2017
// HW3 Towers of Hannoi
// Name: Racquel Fygenson
// Email: rfygenso@usc.edu
// Platform: Mac

#include <stdio.h>
#include "peg.h"


Peg::Peg()//default constructor
{
    mX = 0;
    mY = 0;
    mHeight = 0;
    mWidth = 0;
    mColor = "BLACK";
}

Peg::Peg(int x, int y, int width, int height)
{
    mX = x;
    mY = y;
    mHeight = height;
    mWidth = width;
    mColor = "BLACK";
}

void Peg::addDisk(Disk newDisk)
{
    //set x and y for incoming disk
    newDisk.setX(mX);
    newDisk.setY(mY-newDisk.getHeight()*mDisks.size());
    
    //add the new disk to the peg's vector of disks
    mDisks.add(newDisk);
    
}

Disk Peg::removeDisk()
{
    //create a temp disk to hold the disk that will be removed
    Disk thisDisk;
    
    //define an int to equal the last disk in the peg's vector of disks
    int index;
    index = mDisks.size()-1;
    
    //set the temp disk to be the last disk
    thisDisk = mDisks[index];
    
    //remove the last disk
    mDisks.remove(index);
    
    //return the copy of the last disk
    return thisDisk;
}

void Peg::draw(GWindow& gw)
{
    //draw a peg using the memberVars as parameters
    gw.setColor(mColor);
    gw.fillRect(mX-(mWidth/2), mY-mHeight, mWidth, mHeight); //set the x,y input to be @ bottom center of peg
    
    //draw the disks in the peg's vector of disks
    for(int i = 0; i < mDisks.size(); i++)
    {
        mDisks[i].draw(gw);
    }
    
}
