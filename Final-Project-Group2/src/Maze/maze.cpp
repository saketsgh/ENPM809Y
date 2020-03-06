/**
 * @file Maze.cpp
 * @brief Final Project: Robot Path-planning and simulation using Micro-Mouse Simulator (MMS).
 *
 * File Description: This code file contains methods of maze class which reads the maze from MMS
 * and stores it in a c++ vector representation of a maze.
 *
 * @copyright Copyright (c) 2019 ENPM808Y:Group 2
 *            This project is released under the MIT License.
 *
 * @author Jessica Chen,
 * Saket Gudimetla Hanumath,
 * Carlos Lanza Galeas,
 * Brian Matejevich,
 * Gnyana Teja Samudrala,
 * Sukoon Sarin,
 * Sarvesh Thakur
 *
 *
 * @bug No known bugs.
 * @date 11-18-2019
 *
 */

#include "../API/api.h"
#include "maze.h"
#include <string>

// Access MMS api and define method: to check if there is a wall in specified direction:
bool fp::Maze::isWall(int x, int y, char direction, char roboDir) {
    if(direction == 'n') {
        if (y==fp::Maze::getHeight()-1) {
            return true;
        }
        if (roboDir=='n') {
            return fp::API::wallFront();
        }

        else if (roboDir=='e') {
            return fp::API::wallLeft();
        }
        else if (roboDir == 'w') {
            return fp::API::wallRight();
        }

    }
    else if(direction == 'e') {
        if (x==fp::Maze::getWidth()-1) {
            return true;
        }
        if (roboDir=='n') {
            return fp::API::wallRight();
        }

        else if (roboDir=='e') {
            return fp::API::wallFront();
        }
        else if (roboDir == 's') {
            return fp::API::wallLeft();
        }
    }
    else if(direction == 'w') {
        if (x==0) {
            return true;
        }
        if (roboDir=='n') {
            return fp::API::wallLeft();
        }

        else if (roboDir=='s') {
            return fp::API::wallRight();
        }
        else if (roboDir == 'w') {
            return fp::API::wallFront();
        }
    }
    else {
        if (y==0) {
            return true;
        }
        if (roboDir=='e') {
            return fp::API::wallRight();
        }

        else if (roboDir=='s') {
            return fp::API::wallFront();
        }
        else if (roboDir == 'w') {
            return fp::API::wallLeft();
        }
    }
    return false;
}

// Access height_ attribute and define method: to change the y-coordinate
// in accordance with the vector representation of the maze:
int fp::Maze::convert2MazeY(int y) {
    return (fp::Maze::getHeight()-1) - y;
}

// Access maze attribute and define method: to set a wall in the specified direction:
void fp::Maze::setWall(int x, int y, char direction) {
    int cellY = convert2MazeY(y);
    if(direction == 'n') {
        maze_[cellY][x].replace(0,1,"2");
    }
    else if(direction == 'e') {
        maze_[cellY][x].replace(1,1,"2");
    }
    else if(direction == 's') {
        maze_[cellY][x].replace(2,1,"2");
    }
    else if(direction == 'w') {
        maze_[cellY][x].replace(3,1,"2");
    }
}

//Access maze attribute and define method: to clear a wall in the specified direction:
void fp::Maze::clearWall(int x, int y, char direction) {
    int cellY = convert2MazeY(y);
    if(direction == 'n') {
        maze_[cellY][x].replace(0,1,"1");
    }
    else if(direction == 'e') {
        maze_[cellY][x].replace(1,1,"1");
    }
    else if(direction == 's') {
        maze_[cellY][x].replace(2,1,"1");
    }
    else if(direction == 'w') {
        maze_[cellY][x].replace(3,1,"1");
    }

}

//Using the above methods and define method: to check and update the cell of the maze:
void fp::Maze::updateCell(int x, int y, char roboDir) {
    std::string allDirections{"nesw"};

    for(unsigned int i = 0; i < allDirections.length(); i++) {

        char direction{allDirections[i]};
        if (isWall(x, y, direction, roboDir)) {
            setWall(x, y, direction);
        }
        else {
            clearWall(x, y, direction);
        }
    }

}

void fp::Maze::printCell(int x, int y) {
    std::string allDirections{"nesw"};

    for (unsigned int i=0; i<allDirections.length(); i++) {
        char direction{allDirections[i]};
        if (maze_[15-y][x][i]=='1') {
            fp::API::clearWall(x,y,direction);
        }
        else {
            fp::API::setWall(x,y,direction);
        }
    }
}
