//
//  Pathfinder.cpp
//  Lab 4
//
//  Created by Cam on 10/27/18.
//  Copyright © 2018 Cameron Brown. All rights reserved.
//

#include "Pathfinder.h"
#include <iostream>


using namespace std;

Pathfinder::Pathfinder() {
    for(int i =0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                maze[i][j][k] = 1;
            }
        }
    }
}

string Pathfinder::toString() const {
    ostringstream ss;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5 ; ++j){
            for(int k = 0; k < 5; ++k){
                ss << maze[i][j][k];
                if(k < 4){
                    ss << " ";
                }
            }
            ss << endl;
        }
        if(i < 4){
            ss << endl;
        }
    }
    
    string outputString = ss.str();
    return outputString;
}

void Pathfinder::createRandomMaze(){
    srand(0);
    for(int i=0; i < 5; ++i){
        for(int j=0; j<5; ++j){
            for(int k=0; k<5; ++k){
                maze[i][j][k] = rand() % 2;
            }
        }
    }
    maze[0][0][0] = 1;
    maze[4][4][4] = 1;
    
}

bool Pathfinder::importMaze(string file_name){
    ifstream file(file_name.c_str());
    char token;
    int one_count = 0;
    int zero_count = 0;
    int count = 0;
    if(file.is_open()){
        while(file >> token){
            if(token == '1'){
                one_count++;
                count++;
            }
            else if(token == '0'){
                zero_count++;
                count++;
            }
            else{
                return false;
            }
        }
        file.close();
    }
    else{
        return false;
    }
    if(count!=125){
        return false;
    }
    file.open(file_name);
    if (file.is_open()){
        string line;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++) {
                getline(file, line);
                stringstream ss(line);
                for(int k = 0; k < 5; k++) {
                    int value;
                    ss >> value;
                    if(k == 0 && j == 0 && i == 0){
                        if(value == 0){
                            return false;
                        }
                    }
                    if(k == 4 && j == 4 && i == 4){
                        if(value == 0){
                            return false;
                        }
                    }
                    maze[i][j][k] = value;
                    
                }
                ss.str("");
            }
            getline(file, line);
            
        }
        file.close();
    }
    return true;
}

bool Pathfinder::findPath(int x, int y, int z) {
    
    return true;
}

vector<string> Pathfinder::solveMaze(){
    
    return path;
}
