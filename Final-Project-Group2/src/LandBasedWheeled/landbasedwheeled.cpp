/**
 * @file landbasedwheeled.cpp
 * @brief Header File, containing function prototypes for class LandBasedWheeled.
 *
 * @copyright Copyright (c) 2019 ENPM808Y:Group 2
 *            This project is released under the MIT License.
 * 
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * @author Jessica Chen,
 * Saket Gudimetla Hanumath,
 * Carlos Lanza Galeas,
 * Brian Matejevich,
 * Gnyana Teja Samudrala,
 * Sukoon Sarin,
 * Sarvesh Thakur
 *
 * @bug No known bugs.
 * @date 11-18-2019
 *
 */

/* -- User Defined Includes -- */
#include "landbasedwheeled.h"
#include "../API/api.h"
//#include "../Direction/direction.h"


/**
* @brief GetDirection: Getter function that returns the direction, the robot is facing in
* @return direction_: Char type var indicating direction
*/
char fp::LandBasedWheeled::GetDirection() {

    return direction_;
}


/**
* @brief SetDirection: Setter function that returns the direction, the robot is facing in
* @param dir: Char type input direction variable
* @return void
*/
void fp::LandBasedWheeled::SetDirection(char dir) {

    direction_ = dir;
}

/**
* @brief MoveForward: Function that moves the robot forward by one block
* @return void
*/
void fp::LandBasedWheeled::MoveForward() {

    int x = get_x();
    int y = get_y();
    char curr_dir = GetDirection();
//	double speed = get_speed();
//
    API::moveForward() ;

    // updating x and y position in the maze using mutators set_x and set_y
    // defined in landbasedrobot.h
    if(curr_dir == 'n') {
        y = y + 1;
        set_x(x);
        set_y(y);
    }

    else if(curr_dir == 'e') {
        x = x + 1;
        set_x(x);
        set_y(y);
    }

    else if(curr_dir == 's') {
        y = y - 1;
        set_x(x);
        set_y(y);
    }

    // robot is facing West
    else {
        x = x - 1;
        set_x(x);
        set_y(y);
    }
}


/**
* @brief TurnLeft: Function orients the robot 90 ACW to current orientation
* 
* @return void
*/

void fp::LandBasedWheeled::TurnLeft() {

    char curr_dir = GetDirection();

    API::turnLeft() ;

    if(curr_dir == 'n') {
        curr_dir = 'w' ;
    }

    else if(curr_dir == 'e') {
        curr_dir = 'n' ;
    }

    else if(curr_dir == 's') {
        curr_dir = 'e' ;
    }

    // robot is facing West
    else {
        curr_dir = 's' ;
    }

    // updating current direction
    SetDirection(curr_dir) ;

}

/**
* @brief TurnRight: Function orients the robot 90 CW to current orientation
* 
* @return void
*/

void fp::LandBasedWheeled::TurnRight() {

    char curr_dir = GetDirection();

    API::turnRight() ;

    if(curr_dir == 'n') {
        curr_dir = 'e' ;
    }

    else if(curr_dir == 'e') {
        curr_dir = 's' ;
    }

    else if(curr_dir == 's') {
        curr_dir = 'w' ;
    }

    // robot is facing West
    else {
        curr_dir = 'n' ;
    }

    // updating current direction
    SetDirection(curr_dir) ;

}

/**
* @brief SpeedUp: Function sets the speed using mutator set_speed defined in landbasedrobot.h
* 
* @return void
*/

void fp::LandBasedWheeled::SpeedUp(int speed) {
    set_speed(speed) ;
}
