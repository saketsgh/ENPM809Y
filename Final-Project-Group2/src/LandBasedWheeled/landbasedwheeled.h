/**
 * @file landbasedwheeled.h
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

#pragma once // Include only once during compilation

/* -- C++ Includes -- */
#include <string>

/* -- User Defined Includes -- */
#include "../LandBasedRobot/landbasedrobot.h"


// Declaring namespace fp
namespace fp {

class LandBasedWheeled : public LandBasedRobot {
    public:
        LandBasedWheeled(std::string name = "name", int x = 0, int y = 0, double speed = 1.0,
                         double width = 0.0, double length = 0.0, double height = 0.0,
                         double capacity = 0.0, char direction = 'n',
                         int wheel_number = 0)
            :LandBasedRobot(name, x, y, speed, width, length, height, capacity, direction) {
            wheel_number_ = wheel_number ;
        }

        virtual ~LandBasedWheeled() {}

        // deep copy constructor
        LandBasedWheeled(const LandBasedWheeled &source)
            : LandBasedWheeled{source.name_, source.x_, source.y_,source.speed_,
                               source.width_, source.length_, source.height_, source.capacity_,
                               source.direction_, source.wheel_number_} {
        }

		// declaring public Methods
        virtual char GetDirection() override;
        virtual void MoveForward() override;
        virtual void TurnLeft() override;
        virtual void TurnRight() override;

        void SpeedUp(int) ;
        virtual void SetDirection(char dir) override;

        // acessor for wheel class
        int get_wheel_num() const {
            return wheel_number_ ;
        }

    protected:

        // Attributes
        int wheel_number_ ;


}; // end of class

} // end of namespace
