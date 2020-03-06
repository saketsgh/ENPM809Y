/**
 * @file api.cpp
 * @brief Final Project: Robot Path-planning and simulation using Micro-Mouse Simulator (MMS).
 *
 * File Description: Implementation file for the api class for interaction between the program
 * and the simulator.
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
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 * 
 * @bug No known bugs.
 * @date 11-18-2019
 *
 */

/* -- C++ Includes -- */
#include <cstdlib>
#include <iostream>
/* -- User Defined Includes -- */
#include "api.h"

//--return the width of the maze
int fp::API::mazeWidth() {
    std::cout << "mazeWidth" << std::endl;
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
}

//--return the height of the maze
int fp::API::mazeHeight() {
    std::cout << "mazeHeight" << std::endl;
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
}

//--true if there is a wall in front of the robot, else false
bool fp::API::wallFront() {
    std::cout << "wallFront" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

//--true if there is a wall to the right of the robot, else false
bool fp::API::wallRight() {
    std::cout << "wallRight" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

//--true if there is a wall to the left of the robot, else false
bool fp::API::wallLeft() {
    std::cout << "wallLeft" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

//--move the robot forward by one cell
void fp::API::moveForward() {
    std::cout << "moveForward" << std::endl;
    std::string response;
    std::cin >> response;
    if(response != "ack") {
        std::cerr << response << std::endl;
        throw;
    }
}

//--turn the robot ninty degrees to the right
void fp::API::turnRight() {
    std::cout << "turnRight" << std::endl;
    std::string ack;
    std::cin >> ack;
}

//--turn the robot ninty degrees to the left
void fp::API::turnLeft() {
    std::cout << "turnLeft" << std::endl;
    std::string ack;
    std::cin >> ack;
}

//--display a wall at the given position
void fp::API::setWall(int x, int y, char direction) {
    std::cout << "setWall " << x << " " << y << " " << direction << std::endl;
}

//--clear the wall at the given position
void fp::API::clearWall(int x, int y, char direction) {
    std::cout << "clearWall " << x << " " << y << " " << direction << std::endl;
}

//--set the color of the cell at the given position
void fp::API::setColor(int x, int y, char color) {
    std::cout << "setColor " << x << " " << y << " " << color << std::endl;
}

//--clear the color of the cell at the given position
void fp::API::clearColor(int x, int y) {
    std::cout << "clearColor " << x << " " << y << std::endl;
}

//--clear the color of all cells
void fp::API::clearAllColor() {
    std::cout << "clearAllColor" << std::endl;
}

//--set the text of the cell at the given position
void fp::API::setText(int x, int y, const std::string& text) {
    std::cout << "setText " << x << " " << y << " " << text << std::endl;
}

//--clear the text of the cell at the given position
void fp::API::clearText(int x, int y) {
    std::cout << "clearText " << x << " " << y << std::endl;
}

//--clear the text of all cells
void fp::API::clearAllText() {
    std::cout << "clearAllText" << std::endl;
}

//--true if the reset button was pressed, else false
bool fp::API::wasReset() {
    std::cout << "wasReset" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

//--allow the robot to be moved back to the start of the maze
void fp::API::ackReset() {
    std::cout << "ackReset" << std::endl;
    std::string ack;
    std::cin >> ack;
}
