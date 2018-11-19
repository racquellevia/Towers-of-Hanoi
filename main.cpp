// ITP 365 Fall 2017
// HW3 Towers of Hannoi
// Name: Racquel Fygenson
// Email: rfygenso@usc.edu
// Platform: Mac

#include "gwindow.h"
#include "peg.h"
#include "Disk.h"
#include <iostream>


// Function: promptForDisks
// Purpose: ask user to specify the number of disks to run simulation
// Input: None (other than the user manual input)
// Returns: int numDisks
int promptForDisks()
{
    int numDisks = 2;
    do {
        std::cout << "How many disks would you like? (Choose an integer between 1 and 10)" << std::endl;
        std::cin >> numDisks;
    } while (numDisks > 10 || numDisks < 2);
    
    return numDisks;
}


// Function: promptForPegs
// Purpose: ask user to specify which pegs to start and the end the simulation on
// Input: int pegStart (number that specifies starting peg), int pegEnd (number that specifies ending peg)
// Returns: nothing
void promptForPegs(int& pegStart, int& pegEnd)
{
    do {
        std::cout << "Which peg would you like to start? (Choose: '1', '2', or '3')" << std::endl;
        std::cin >> pegStart;
    } while ((pegStart > 3 || pegStart < 1));
    
    do {
        std::cout << "Which peg would you like to end? (Choose a different peg than you chose for start: '1', '2', or '3')" << std::endl;
        std::cin >> pegEnd;
    } while (pegEnd > 3 || pegEnd < 1 || pegEnd == pegStart);
}

// Function: draw
// Purpose: draw the pegs/disks throughout the simulation, as the algorithm updates
// Input: Gwindow gw, Vector of Pegs myPegs
// Returns: nothing
void draw(GWindow& gw, Vector<Peg>& myPegs)
{
    gw.clear();
    for(int i =0; i< 3; i ++)
    {
        myPegs[i].draw(gw);
    }
    pause(100);
}

// Function: moveDisk
// Purpose: removes a disk from start peg, stores it in a tempDisk, and adds the disk to end peg
// Input: GWindow gw, Vector of Pegs myPegs, int pegStart (starting peg), int pegEnd (ending peg)
// Returns: nothing
void moveDisk(GWindow& gw, Vector<Peg>& myPegs, int pegStart, int pegEnd)
{
    Disk tempDisk;
    tempDisk = myPegs[pegStart].removeDisk();
    myPegs[pegEnd].addDisk(tempDisk);
    draw(gw, myPegs);
    
}

// Function: towerSolver
// Purpose: Use recursion to shift the disks from (top of) start peg to end peg, one at a time, without placing larger disks on top of smaller disks
// Input: GWindow gw, Vector of Pegs myPegs, int pegStart (starting peg), int pegEnd (ending peg), int moveDiskNum (number of Disks to be moved)
// Returns: nothing
void towerSolver(GWindow& gw, Vector<Peg>& myPegs, int pegStart, int pegEnd, int moveDiskNum)
{
    //designate the temporary peg (as the one peg not specifed to start or end)
    int pegTemp = 3 - (pegStart + pegEnd);
    
    //base case, when there are no disks left to move
    if(moveDiskNum == 0)
    {
        return;
    }
    //use recursion to shift disks according to rules
    else
    {
        // Transfer N−1 Disks from “start” to “temp”. This leaves Disk 0 alone on “start”
        towerSolver(gw, myPegs, pegStart, pegTemp, moveDiskNum-1);
        
        // Move Disk 0 from “start” to “end”
        moveDisk(gw, myPegs, pegStart, pegEnd);
       
        // Transfer N−1 Disks from “temp” to “end” so they sit on Disk 0
        towerSolver(gw, myPegs, pegTemp, pegEnd, moveDiskNum-1);
    }
}

int main(int argc, char** argv)
{
    // initialize the start and end peg
    int pegStart = 1;
    int pegEnd = 3;
    //create a vector of pegs
    Vector<Peg> myPegs;
    
    
    
    // Create a window
    GWindow gw(800, 500);
    std::cout << "Welcome to the Towers of Hanoi solver." <<std::endl<<std::endl;
    std::cout << "For more information about Towers of Hanoi check out https://en.wikipedia.org/wiki/Tower_of_Hanoi" << std::endl<<std::endl;
    promptForPegs(pegStart, pegEnd); //set the starting and ending pegs
    
    
    //change user-inputs to correlate correctly with Vector myPegs index
    pegStart--;
    pegEnd--;
    
    //store the desired number of disks
    int numDisks = promptForDisks();
    
    std::cout << "Your Towers of Hanoi will be constructed and solved!" << std::endl;
    
    //create 3 pegs for tower of hanoi setup in a vector called myPegs
    for(int i = 0; i < 3; i++)
    {
        myPegs.add(Peg(200*(i+1),480, 5, 400));
    }
    
    //add the requested number of disks to the starting peg
    for(int i =0; i <numDisks; i++)
    {
        int width = 200 - i*20;
        myPegs[pegStart].addDisk(Disk(0,0,width, 20));
    }
    
    //draw the pegs with their disks
    draw(gw, myPegs);
    
    //solve the tower of hanoi puzzle
    towerSolver(gw, myPegs, pegStart, pegEnd, numDisks);
    
    
    return 0;
}
