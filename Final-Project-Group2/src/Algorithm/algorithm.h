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
* Header file for Algorithm Class. Includes attributes and methods to implement
* path finding strategy for the robot.
*
* @bug No known bugs.
* @date 11-29-2019
*/

#pragma once // Include only once during compilation.

/* -- C++ Includes -- */
#include <iostream>
#include <string>
#include <vector>

/* -- User-defined header files -- */
#include "../Maze/maze.h"
#include "../LandBasedRobot/landbasedrobot.h"
#include <memory>

// Declaring Namespace fp
namespace fp {

class Algorithm {
    public:

        // Constructor:
        Algorithm(int leftGoalCrnX=7, int leftGoalCrnY=7):
            leftGoalCrnX_{leftGoalCrnX},
            leftGoalCrnY_{leftGoalCrnY},
            blockedCells_(fp::API::mazeHeight(),std::vector<std::string>(fp::API::mazeWidth(),"0")) {
        }

        // Destructor:
        ~Algorithm() {
        }

        // Methods
        void solve_V2(std::shared_ptr<fp::LandBasedRobot> robot_);
        void turn(std::shared_ptr<fp::LandBasedRobot> robot_, char changDir);
        bool checkGoal(int x, int y);
        void plotPath(std::vector<char> path, fp::Maze maze,  std::shared_ptr<fp::LandBasedRobot> robot_);
        std::vector<char> DFS(fp::Maze maze, int startX, int startY, std::vector<std::vector<std::string>> visitTracker);
        void solve( std::shared_ptr<fp::LandBasedRobot> robot_);

        // Attributes

        //Attribute - x coordinate of left corner cell of goal.
        int leftGoalCrnX_;

        //Attribute - y coordinate of left corner cell of goal.
        int leftGoalCrnY_;

        //Attribute - To track the cells which are blocked on all three sides.
        std::vector<std::vector<std::string>> blockedCells_;

}; // close class: Algorithm

} // close namespace: fp
