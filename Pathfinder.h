//
//  Pathfinder.h
//  Lab 4
//
//  Created by Cam on 10/27/18.
//  Copyright © 2018 Cameron Brown. All rights reserved.
//

#ifndef Pathfinder_h
#define Pathfinder_h

#include <stdio.h>
#include "PathfinderInterface.h"
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

using namespace std;

class Pathfinder : public PathfinderInterface {
public:
    Pathfinder();
    string toString() const;
    void createRandomMaze();
    bool importMaze(string file_name);
    bool findPath(int x, int y, int z);
    vector<string> solveMaze();
protected:
    int maze[5][5][5];
    vector<string> path;
};

#endif /* Pathfinder_h */
