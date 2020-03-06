/**
 * @file landbasedtracked.h
 * @brief Header File, containing function prototypes for class LandBasedTracked.
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

/* -- C++ Includes -- */
#pragma once
//#include "../Direction/direction.h"
#include "../LandBasedRobot/landbasedrobot.h"


// Namespace Declaration
namespace fp {

class LandBasedTracked : public LandBasedRobot {
    public:
        LandBasedTracked(std::string name = "name", int x = 0, int y = 0, double speed = 1.0,
                         double width = 0.0, double length = 0.0, double height = 0.0,
                         double capacity = 0.0, char direction = 'n',
                         std::string track_type = "none")
            :LandBasedRobot(name, x, y, speed, width, length, height, capacity, direction) {

        }

        // deep copy constructor
        LandBasedTracked(const LandBasedTracked &source)
            : LandBasedTracked{source.name_, source.x_, source.y_,source.speed_,
                               source.width_, source.length_, source.height_, source.capacity_,
                               source.direction_, source.track_type_} {
        }

        virtual ~LandBasedTracked() {
        }

		// Public Methods
        virtual char GetDirection() override;
        virtual void MoveForward() override;
        virtual void TurnLeft() override;
        virtual void TurnRight() override;
        void SetDirection(char dir);

    protected:

        // Attributes
        std::string track_type_ ;


}; // end of class

} // end of namespace
