/**
* @file main.cpp
*
* @brief ENPM809Y: Final Project - Robot Path-planning and simulation using Micro-Mouse Simulator (MMS).
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
* This project generates a path from the current position(S) of a robot in a maze
* to the center of the maze(G). Once a path is generatedm the robot is tasked to follow the path.
* The micromouse simulator is used to display the result on the screen. The prorgam exits when either
* the robot reaches G or there is no solution from S to G.
*
* @bug No known bugs.
* @date 11-29-2019
*/


/* -- C++ Includes -- */
#include <iostream>

/* -- User-defined header files -- */
#include "./src/API/api.h"
#include "./src/Maze/maze.h"
#include "./src/Algorithm/algorithm.h"
#include "./src/LandBasedRobot/landbasedrobot.h"
#include "./src/LandBasedWheeled/landbasedwheeled.h"
#include <memory>
/**
* @brief main function
*
* The function is used to initialize the map of the environment, mobileRobot
* objects and call the algorithm to search the path from robot start position
* to target goal position.
*
* @return 0 Exit success
*/

int main() {

    // Create an instance of a wheeled robot, a smart pointer of type "shared"
    std::shared_ptr<fp::LandBasedRobot> wheeled{new fp::LandBasedWheeled("Husky")} ;

    // Create an object for class Algorithm
    fp::Algorithm algo;

    // Solve the maze with a path finding algorithm
    algo.solve(wheeled);

//    algo.solve_V2(wheeled);

    // Return success
    return 0;
}
