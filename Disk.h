// ITP 365 Fall 2017
// HW3 Towers of Hannoi
// Name: Racquel Fygenson
// Email: rfygenso@usc.edu
// Platform: Mac

#pragma once
#include "gwindow.h"

class Disk
{
public:
    // Function: Default Constructor
    // Purpose: Initialize Disk obj
    // Input: None
    // Returns: Nothing
    Disk();
    
    //Function: Parameterized constructor
    //Purpose: Set x, y, width, and height
    //Input:   Int values for x y coordinates, and width, height of disk
    //Output: Nothing
    Disk(int x, int y, int width, int height);

    
    //Function: setX
    //Purpose: Set just the x coordinate of the disk
    //Input:   Int values for x coordinate
    //Output: Nothing
    void setX(int x);
    
    //Function: setY
    //Purpose: Set just the y coordinate of the disk
    //Input:   Int values for y coordinate
    //Output: Nothing
    void setY(int y);
    
    //Function: getHeigth
    //Purpose: return the height of the disk
    //Input:   Nothing
    //Output: the height of the disk
    int getHeight();
    
    //Function: draw
    //Purpose: draw the disk based on memberVars
    //Input:   GWindow gw to draw in
    //Output: nothing (visual output is the rectangel representing the disk)
    void draw(GWindow& gw);

    
private:
    int mX;
    int mY;
    int mHeight;
    int mWidth;
    std::string mColor;
};
