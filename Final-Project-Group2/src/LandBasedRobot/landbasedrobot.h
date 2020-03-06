/**
 * @file landbasedrobot.cpp
 * @brief Implementation file for LandBasedRobot Class
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

#pragma once // Include header files once only

/* -- C++ Includes -- */
#include <string>

// Namespace Declaration
namespace fp {
class LandBasedRobot {
    
	public:
        LandBasedRobot(std::string name, int x, int y, double speed, double width,
                       double length, double height, double capacity, char direction)
            :name_{name}, x_{x}, y_{y}, speed_{speed}, width_{width}, length_{length}, height_{height},
             capacity_{capacity}, direction_{direction}
        {}

        virtual ~LandBasedRobot() {}

        // declaring methods
        virtual char GetDirection() = 0;
        virtual void MoveForward() = 0;
        virtual void TurnLeft() = 0;
        virtual void TurnRight() = 0;
        virtual void SetDirection(char dir) = 0;

        // Accessors
        int get_x() const {
            return x_;
        }

        int get_y() const {
            return y_;
        }

        double get_length() const {
            return length_;
        }

        double get_width() const {
            return width_;
        }

        double get_height() const {
            return height_;
        }

        double get_speed() const {
            return speed_;
        }

        double get_capacity() const {
            return capacity_;
        }

        // mutators
        void set_x(int x) {
            x_ = x;
        }

        void set_y(int y) {
            y_ = y;
        }

        void set_length(double length) {
            length_ = length;
        }

        void set_width(double width) {
            width_ = width;
        }

        void set_height(double height) {
            height_ = height;
        }

        void set_speed(double speed) {
            speed_ = speed;
        }


        void set_capacity(double capacity) {
            capacity_ = capacity;
        }


    protected:

        // declaring the arrtributes
        std::string name_ ; // Name of the robot
        int x_ ;
        int y_ ;
        double speed_ ;
        double width_ ;
        double length_ ;
        double height_ ;
        double capacity_ ;
        char direction_ ;


}; // end of class

} // end of namespace fp
