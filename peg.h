// ITP 365 Fall 2017
// HW3 Towers of Hannoi
// Name: Racquel Fygenson
// Email: rfygenso@usc.edu
// Platform: Mac

#include "string.h"
#pragma once
#include "gwindow.h"
#include "vector.h"
#include "Disk.h"

class Peg
{ public:
    // Function: Default Constructor
    // Purpose: Initialize Peg obj
    // Input: None
    // Returns: Nothing
    Peg();
    
    //Function: Parameterized constructor
    //Purpose: Set x, y, width, and height
    //Input:   Int values for x, y coordinates and width, height of peg
    //Output: Nothing
    Peg(int x, int y, int width, int height);
    
    //Function: addDisk
    //Purpose: set x and y coordinates of desk, add it to a peg
    //Input:   Disk object to add
    //Output: Nothing
    void addDisk(Disk newDisk);
    
    //Function: removeDisk
    //Purpose: remove and return the last disk in the peg's vector of disks
    //Input:  Nothing
    //Output: the removed (last) disk
    Disk removeDisk();
    
    //Function: draw
    //Purpose: draw the peg and its disks
    //Input:   GWindow gw to draw in
    //Output: Nothing (visual output in the GWindow)
    void draw(GWindow& gw);

    
 private:
    int mX;
    int mY;
    int mHeight;
    int mWidth;
    Vector<Disk> mDisks;
    std::string mColor;
};
