/**
* @file main.cpp
*
* @brief ENPM809Y: Final Project
*
* @author Jessica Chen
* Saket Gudimetla Hanumath
* Carlos Lanza Galeas
* Brian Matejevich
* Gnyana Samudrala
* Sukoon Sarin
* Sarvesh Thakur
*
* @version 1.0
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* @section DESCRIPTION
*
* Implementation code for class Algorithm. Includes definitions for turn(),
* checkGoal(), plotPath() and solve() functions.
*
* @bug No known bugs.
* @date 11-29-2019
*/

/* -- C++ Includes -- */
#include <vector>
#include <bits/stdc++.h>

/* -- User Defined Includes -- */
#include "algorithm.h"
#include "../Maze/maze.h"


/**
* @brief turn: Function turns the robot orientation.
*
* @param robot_ pointer: to LandBasedRobot class instance
* @param changDir: character type variable to indicate change of direction
*
* @return void
*/
void fp::Algorithm::turn(std::shared_ptr<fp::LandBasedRobot> robot_, char changDir) {

    while(changDir!=robot_->GetDirection()) {
        if (changDir=='e') {
            robot_->TurnRight();
        }
        else if (changDir=='w') {
            robot_->TurnLeft();
        }
        else {
            robot_->TurnLeft();
        }
    }

}

/**
* @brief checkGoal: Function checks if a coordinate is a goal block.
*
* @param int x
* @param int y
*
* @return TRUE if coordinate is the goal; Otherwise FALSE
*/
bool fp::Algorithm::checkGoal(int x, int y) {
    if(x == leftGoalCrnX_ && y == leftGoalCrnY_) {
        return true;
    }
    else if(x==leftGoalCrnX_+1 && y == leftGoalCrnY_) {
        return true;
    }
    else if(x==leftGoalCrnX_ && y == leftGoalCrnY_+1) {
        return true;
    }
    else if(x==leftGoalCrnX_+1 && y == leftGoalCrnY_+1) {
        return true;
    }
    else {
        return false;
    }
}

/**
* @brief plotPath: Function plots the path for the navigating robot.
*
* @param path, vector of char type
* @param maze, instance of class Maze
* @param robot_, instance of class LandBasedRobot
*
* @return void
*/

void fp::Algorithm::plotPath(std::vector<char> path, fp::Maze maze,  std::shared_ptr<fp::LandBasedRobot> robot_) {
    robot_->set_x(0);
    robot_->set_y(0);
    robot_->SetDirection('n');
    for(std::size_t i=0; i<path.size(); i++) {
        if (i>0) {
            fp::API::setColor(robot_->get_x(),robot_->get_y(), 'w');

        }
        maze.printCell(robot_->get_x(),robot_->get_y());
        fp::Algorithm::turn(robot_, path[i]);
        robot_->MoveForward();
    }
}

/**
* @brief solve_V2: Function Implements DFS for finding path by updating the maze and exploring using DFS at the same time.
*
* @param robot_: Instance of class LandBasedRobot
*
* @return void
*/

void fp::Algorithm::solve_V2(std::shared_ptr<fp::LandBasedRobot> robot_) {

    std::cerr<<"Running solve V2 method"<<std::endl;

    //Create a maze class
    fp::Maze maze;

    //Color goal area
    fp::API::setColor(leftGoalCrnX_,leftGoalCrnY_, 'g');
    fp::API::setColor(leftGoalCrnX_+1,leftGoalCrnY_, 'g');
    fp::API::setColor(leftGoalCrnX_,leftGoalCrnY_+1, 'g');
    fp::API::setColor(leftGoalCrnX_+1,leftGoalCrnY_+1, 'g');
    char changDir{'n'};
    int changDirNum{0};

    //Update the maze vector
    maze.updateCell(robot_->get_x(), robot_->get_y(), robot_->GetDirection());
    fp::API::setColor(robot_->get_x(),robot_->get_y(),'c');

    int numMoves{0};

    //Track of directions taken from each cell
    std::vector<std::vector<std::string>> dirTracker(maze.getHeight(), std::vector<std::string>(maze.getWidth(), "0000"));
    std::vector<std::vector<std::string>> visitTracker(maze.getHeight(), std::vector<std::string>(maze.getWidth(), "0"));
    std::vector<char> path{};
    std::vector<int> multNodesX{};
    std::vector<int> multNodesY{};

    int lastX{-1};
    int lastY{-1};

    while(true) {
        visitTracker[maze.getHeight()-1-robot_->get_y()][robot_->get_x()] = "1";
        if (maze.maze_[maze.getHeight()-1-robot_->get_y()][robot_->get_x()] == "0000") {
            maze.updateCell(robot_->get_x(),robot_->get_y(), robot_->GetDirection());
            fp::API::setColor(robot_->get_x(),robot_->get_y(),'c');

        }

        if (fp::API::wasReset()) {
            break;
        }


        if (fp::Algorithm::checkGoal(robot_->get_x(),robot_->get_y())) {
            int goalX = robot_->get_x();
            int goalY = robot_->get_y();
            fp::API::ackReset();
            fp::API::clearAllColor();
            fp::API::clearAllText();
            fp::API::setText(0,0,"Start");
            fp::API::setColor(0,0,'r');
            fp::API::setText(goalX, goalY, "Goal");
            fp::API::setColor(goalX, goalY, 'g');
            fp::API::setColor(goalX+1,goalY,'g');
            fp::API::setColor(goalX, goalY+1, 'g');
            fp::API::setColor(goalX+1,goalY+1,'g');
            fp::Algorithm::plotPath(path, maze, robot_);
            break;
        }

        std::string possMoves{"2222"};
        if (maze.maze_[maze.getHeight()-1-robot_->get_y()][robot_->get_x()][2]=='1' &&
                visitTracker[maze.getHeight()-1-robot_->get_y()+1][robot_->get_x()]=="0" &&
                dirTracker[maze.getHeight()-1-robot_->get_y()][robot_->get_x()][0]!='1') {
            possMoves[0] = '1';
        }
        if (maze.maze_[maze.getHeight()-1-robot_->get_y()][robot_->get_x()][1]=='1' &&
                visitTracker[maze.getHeight()-1-robot_->get_y()][robot_->get_x()+1]=="0" &&
                dirTracker[maze.getHeight()-1-robot_->get_y()][robot_->get_x()][1]!='1') {
            possMoves[1] = '1';
        }
        if (maze.maze_[maze.getHeight()-1-robot_->get_y()][robot_->get_x()][0]=='1' &&
                visitTracker[maze.getHeight()-1-robot_->get_y()-1][robot_->get_x()]=="0" &&
                dirTracker[maze.getHeight()-1-robot_->get_y()][robot_->get_x()][2]!='1') {
            possMoves[2] = '1';
        }
        if (maze.maze_[maze.getHeight()-1-robot_->get_y()][robot_->get_x()][3]=='1' &&
                visitTracker[maze.getHeight()-1-robot_->get_y()][robot_->get_x()-1]=="0" &&
                dirTracker[maze.getHeight()-1-robot_->get_y()][robot_->get_x()][3]!='1') {
            possMoves[3] = '1';
        }

        numMoves = std::count(possMoves.begin(), possMoves.end(),'1');
        fp::API::setText(robot_->get_x(),robot_->get_y(),std::to_string(numMoves));

        if(numMoves==0) {

            fp::API::ackReset();
            if (multNodesX.size()==0) {
                break;
            }
            robot_->set_x(0);
            robot_->set_y(0);
            robot_->SetDirection('n');
            changDir='n';
            changDirNum=0;
            for (auto &v: visitTracker) {
                std::fill(v.begin(), v.end(), "0");
            }
            lastX = multNodesX.back();
            multNodesX.pop_back();
            lastY = multNodesY.back();
            multNodesY.pop_back();
            int iter{0};
            std::vector<char> newPath{};
            while(true) {
                if (lastX==robot_->get_x() && lastY==robot_->get_y()) {
                    break;
                }
                fp::Algorithm::turn(robot_, path[iter]);
                changDir = path[iter];
                robot_->MoveForward();
                iter++;
                visitTracker[maze.getHeight()-1-robot_->get_y()][robot_->get_x()]="1";
                newPath.push_back(robot_->GetDirection());

            }
            path.clear();
            path = newPath;
            continue;
        }

        for (unsigned int i=0; i<4; i++) {
            if (possMoves[i]=='1') {
                if (numMoves>1) {
                    dirTracker[maze.getHeight()-1-robot_->get_y()][robot_->get_x()][i]='1';
                    multNodesX.push_back(robot_->get_x());
                    multNodesY.push_back(robot_->get_y());
                    changDirNum = i;
                    break;
                }
                else {
                    changDirNum = i;
                    break;
                }
            }
        }
        if (changDirNum==0) {
            changDir='s';
        }
        else if (changDirNum == 1) {
            changDir='e';
        }
        else if (changDirNum==2) {
            changDir='n';
        }
        else {
            changDir='w';
        }

        fp::Algorithm::turn(robot_,changDir);
        robot_->SetDirection(changDir);
        path.push_back(robot_->GetDirection());
        robot_->MoveForward();

    }
}

/**
* @brief solve: Function takes in the maze and returns the vector of directions to be followed.
*
* @param maze: Instance of class maze
* @param startX: Starting x-coordinate in the maze
* @param startY: Starting y-coordinate in the maze
* @param visitTracker: To track the status of the cell if visited or not
*
* @return a vector of characters containing the directions to be followed
*/

std::vector<char> fp::Algorithm::DFS(fp::Maze maze, int startX, int startY, std::vector<std::vector<std::string>> visitTracker) {

    int x{startX};
    int y{startY};
    std::vector<char> path{};
    std::vector<int> pastX{};
    std::vector<int> pastY{};

    int i{0};

    while(true) {

        if (fp::Algorithm::checkGoal(x,y)) {
            break;
        }

        if(maze.maze_[maze.getHeight()-1-y][x][2] != '2' && y-1>=0 && visitTracker[maze.getHeight()-1-(y-1)][x] == "0" &&
                blockedCells_[maze.getHeight()-1-(y-1)][x] == "0") {
            path.push_back('s');
            y -= 1;
            visitTracker[maze.getHeight()-1-y][x] = "1";
            pastX.push_back(x);
            pastY.push_back(y);
        }
        else if (maze.maze_[maze.getHeight()-1-y][x][1] != '2' && x+1<maze.getWidth() && visitTracker[maze.getHeight()-1-y][x+1] == "0" &&
                 blockedCells_[maze.getHeight()-1-y][x+1] == "0") {
            path.push_back('e');
            x += 1;
            visitTracker[maze.getHeight()-1-y][x] = "1";
            pastX.push_back(x);
            pastY.push_back(y);
        }
        else if (maze.maze_[maze.getHeight()-1-y][x][0] != '2' && y+1<maze.getHeight() && visitTracker[maze.getHeight()-1-(y+1)][x] == "0" &&
                 blockedCells_[maze.getHeight()-1-(y+1)][x] == "0") {
            path.push_back('n');
            y += 1;
            visitTracker[maze.getHeight()-1-y][x] = "1";
            pastX.push_back(x);
            pastY.push_back(y);
        }
        else if (maze.maze_[maze.getHeight()-1-y][x][3] != '2' && x-1>=0 && visitTracker[maze.getHeight()-1-y][x-1] == "0" &&
                 blockedCells_[maze.getHeight()-1-y][x-1] == "0") {
            path.push_back('w');
            x -= 1;
            visitTracker[maze.getHeight()-1-y][x] = "1";
            pastX.push_back(x);
            pastY.push_back(y);
        }
        else {
            
            int numBlocks = std::count(maze.maze_[maze.getHeight()-1-y][x].begin(), maze.maze_[maze.getHeight()-1-y][x].end(),'2');
            if (y-1>=0) {
                if (blockedCells_[maze.getHeight()-1-(y-1)][x] == "1") {
                    numBlocks+=1;
                }
            }
            if (y+1<maze.getHeight()) {
                if (blockedCells_[maze.getHeight()-1-(y+1)][x] == "1") {
                    numBlocks+=1;
                }
            }
            if (x+1<maze.getHeight()) {
                if (blockedCells_[maze.getHeight()-1-y][x+1] == "1") {
                    numBlocks+=1;
                }
            }
            if (x-1>=0) {
                if (blockedCells_[maze.getHeight()-1-y][x-1] == "1") {
                    numBlocks+=1;
                }
            }

            if (numBlocks>=2) {
                blockedCells_[maze.getHeight()-1-y][x] = "1";
                std::vector<char> path{};
                return path;
            }
            else {
                x = pastX.back();
                pastX.pop_back();
                y = pastY.back();
                pastY.pop_back();
            }
        }

        fp::API::setColor(x,y,'y');
    }

    return path;
}

/**
* @brief solve: Function Implements DFS for finding path as specified in psuedo code given in the project documentation
*
* @param robot_: Instance of class LandBasedRobot
*
* @return void
*/

void fp::Algorithm::solve(std::shared_ptr<fp::LandBasedRobot> robot_) {


    std::cerr<<"Running solve method"<<std::endl;

    fp::Maze maze;
    std::vector<char> path;
    std::vector<std::vector<std::string>> visitTracker(maze.getHeight(), std::vector<std::string>(maze.getWidth(), "0"));
    visitTracker[maze.getHeight()-1][0] = "1";
    fp::API::setText(0,0,"Start");
    fp::API::setColor(0,0,'r');
    fp::API::setText(leftGoalCrnX_,leftGoalCrnY_,"Goal");
    fp::API::setText(leftGoalCrnX_+1,leftGoalCrnY_,"Goal");
    fp::API::setText(leftGoalCrnX_,leftGoalCrnY_+1,"Goal");
    fp::API::setText(leftGoalCrnX_+1,leftGoalCrnY_+1,"Goal");
    fp::API::setColor(leftGoalCrnX_,leftGoalCrnY_, 'g');
    fp::API::setColor(leftGoalCrnX_+1,leftGoalCrnY_, 'g');
    fp::API::setColor(leftGoalCrnX_,leftGoalCrnY_+1, 'g');
    fp::API::setColor(leftGoalCrnX_+1,leftGoalCrnY_+1, 'g');

    while(true) {

        if (fp::API::wasReset()) {
            break;
        }

        if (blockedCells_[maze.getHeight()-1][1]=="1" && blockedCells_[maze.getHeight()-2][0]=="1"){
            std::cerr<<"No path found"<<std::endl;
            break;
        }

        if (fp::Algorithm::checkGoal(robot_->get_x(),robot_->get_y())) {
            fp::API::setColor(robot_->get_x(), robot_->get_y(),'g');
            break;
        }

        path = fp::Algorithm::DFS(maze, robot_->get_x(), robot_->get_y(), visitTracker);

        if (path.size()==0) {
            for (auto &v: visitTracker) {
                std::fill(v.begin(), v.end(), "0");
            }
            visitTracker[maze.getHeight()-1][0] = "1";
            fp::API::ackReset();
            robot_->set_x(0);
            robot_->set_y(0);
            robot_->SetDirection('n');
            fp::API::clearAllColor();
            fp::API::setColor(0,0,'r');
            fp::API::setColor(leftGoalCrnX_,leftGoalCrnY_, 'g');
            fp::API::setColor(leftGoalCrnX_+1,leftGoalCrnY_, 'g');
            fp::API::setColor(leftGoalCrnX_,leftGoalCrnY_+1, 'g');
            fp::API::setColor(leftGoalCrnX_+1,leftGoalCrnY_+1, 'g');
            continue;
        }

        for (unsigned int i=0; i< path.size(); i++) {

            if (maze.isWall(robot_->get_x(), robot_->get_y(), path[i], robot_->GetDirection())) {
                maze.setWall(robot_->get_x(), robot_->get_y(), path[i]);
                break;
            }
            maze.updateCell(robot_->get_x(),robot_->get_y(),robot_->GetDirection());
            fp::Algorithm::turn(robot_, path[i]);
            robot_->MoveForward();
            maze.updateCell(robot_->get_x(),robot_->get_y(),robot_->GetDirection());
            visitTracker[maze.getHeight()-1-robot_->get_y()][robot_->get_x()]="1";
            maze.printCell(robot_->get_x(), robot_->get_y());
            fp::API::setColor(robot_->get_x(), robot_->get_y(),'w');

        }

        
    }

}
