/**
 * @file landbasedrobot.cpp
 * @brief Implementation file for LandBasedRobot Class
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
 
/* -- User Defined Includes -- */
#include "landbasedrobot.h" // Includes prototypes and definitions for the Attributes and methods of class LandBasedRobot.
#include "../API/api.h"


// returns the direction_ attribute of the robot
char fp::LandBasedRobot::GetDirection(){	
	return direction_;
}

// sets the direction attribute of the robot
void fp::LandBasedRobot::SetDirection(char dir){	
	direction_ = dir; 
}

/* moves the robot forward in the current direction and position
 * and updates the maze coordinates accordingly
 */ 
void fp::LandBasedRobot::MoveForward(){
	
	int x = get_x();
	int y = get_y();
	char curr_dir = GetDirection();

	fp::API::moveForward() ;
	
	// updating x and y position in the maze using mutators set_x and set_y 
	// defined in landbasedrobot.h  
	if(curr_dir == 'n'){
		y = y + 1; 
		set_x(x);
		set_y(y);
	}
	
	else if(curr_dir == 'e'){
		x = x + 1; 
		set_x(x);
		set_y(y);
	}
	
	else if(curr_dir == 's'){
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

/* Turns the robot left from the current direction and position
 * and updates the direction_ attribute accordingly
 */
void fp::LandBasedRobot::TurnLeft(){
	
	char curr_dir = GetDirection();
	
	fp::API::turnLeft() ;
	
	if(curr_dir == 'n'){
		curr_dir = 'w' ;
	}
	
	else if(curr_dir == 'e'){
		curr_dir = 'n' ;
	}
	
	else if(curr_dir == 's'){
		curr_dir = 'e' ;
	}
	
	// robot is facing West
	else {
		curr_dir = 's' ;
	}	
	
	// updating current direction
	SetDirection(curr_dir) ;
	
}		

/* Turns the robot right from the current direction and position
 * and updates the direction_ attribute accordingly
 */
void fp::LandBasedRobot::TurnRight(){
    
	char curr_dir = GetDirection();
	
	fp::API::turnRight() ;
	
	if(curr_dir == 'n'){
		curr_dir = 'e' ;
	}
	
	else if(curr_dir =='e'){
		curr_dir = 's' ;
	}
	
	else if(curr_dir == 's'){
		curr_dir = 'w' ;
	}
	
	// robot is facing West
	else {
		curr_dir = 'n' ;
	}	
	
	// updating current direction
	SetDirection(curr_dir) ;
	
}
