/**
 * @file api.h
 * @brief Final Project: Robot Path-planning and simulation using Micro-Mouse Simulator (MMS).
 *
 * File Description: This is a header file for the api class for interaction between the program
 * and the simulator.
 *
 * @copyright Copyright (c) 2019 ENPM808Y:Group 2
 *            This project is released under the MIT License.
 *
 * @author Jessica Chen,
 * Saket Gudimetla Hanumath,
 * Carlos Lanza Galeas
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

#pragma once
#include <string>

//! An api class
/*! An api class responsible for the interaction between our program and the simulator
 * to visualize the path planning algorithm step-wise.
 */

namespace fp {
class API {
        //! A constructor
        /*! Nothing to initialize in the constructor of this class.*/
        API();

        //! A destructor
        ~API();

    public:
        //! A static prototype to get the width of the maze.
        /*!
         * \return the width of the maze.
         */
        static int mazeWidth();

        //! A static prototype to get the height of the maze.
        /*!
         * \return the height of the maze.
         */
        static int mazeHeight();

        //! A static prototype to check there is a wall in front of the robot.
        /*!
         * \return true if there is a wall in front of the robot, else false.
         */
        static bool wallFront();

        //! A static prototype to check there is a wall to the right of the robot.
        /*!
         * \return true if there is a wall to the right of the robot, else false.
         */
        static bool wallRight();

        //! A static prototype to check there is a wall to the left of the robot.
        /*!
         * \return true if there is a wall to the left of the robot, else false.
         */
        static bool wallLeft();

        //! A static prototype to move the robot forward by one cell.
        /*!
         * \brief Moves the robot forward by a single cell.
         */
        static void moveForward();

        //! A static prototype to turn the robot ninty degrees to the right.
        /*!
         * \brief Turns the robot ninty degrees to the right.
         */
        static void turnRight();

        //! A static prototype to turn the robot ninty degrees to the left.
        /*!
         * \brief Turns the robot ninty degrees to the left.
         */
        static void turnLeft();

        //! A static prototype to display the wall at the given position.
        /*!
         * \brief Displays a wall in the given direction.
         * \param x the x-coordinate of the cell.
         * \param y the y-coordinate of the cell.
         * \param direction the direction in which the wall is to be shown.
         */
        static void setWall(int x, int y, char direction);

        //! A static prototype to clear the wall at the given position.
        /*!
         * \brief Clears the wall in the given direction.
         * \param x the x-coordinate of the cell.
         * \param y the y-coordinate of the cell.
         * \param direction the direction in which the wall is to cleared.
         */
        static void clearWall(int x, int y, char direction);

        //! A static prototype to set the color of the cell at the given position.
        /*!
         * \brief Sets the color of the cell at the given position.
         * \param x the x-coordinate of the cell.
         * \param y the y-coordinate of the cell.
         * \param color the character of the color to be set.
         */
        static void setColor(int x, int y, char color);

        //! A static prototype to clear the color of the cell at the given position.
        /*!
         * \brief Clears the color of the cell at the given postion.
         * \param x the x-coordinate of the cell.
         * \param y the y-coordinate of the cell.
         */
        static void clearColor(int x, int y);

        //! A static prototype to clear the color of all the cells.
        /*!
         * \brief Clears the color of all the cells.
         */
        static void clearAllColor();

        //! A static prototype to set the text of the cell at the given position.
        /*!
         * \brief Set the text of the cell at the given position.
         * \param x the x-coordinate of the cell.
         * \param y the y-coordinate of the cell.
         * \param text the text that should be set in the cell.
         */
        static void setText(int x, int y, const std::string& text);

        //! A static prototype to clear the text of the cell at the given position.
        /*!
         * \brief Clear the text of the cell at the given position.
         * \param x the x-coordinate of the cell.
         * \param y the y-coordinate of the cell.
         */
        static void clearText(int x, int y);

        //! A static prototype to clear the text of all cells.
        /*!
         * \brief Clears the text of all cells.
         */
        static void clearAllText();

        //! A static prototype to know when reset button is pressed.
        /*!
         * \return true if the reset button is pressed, else false.
         */
        static bool wasReset();

        //! A static prototype to allow the robot to be moved back to the start of the maze.
        /*!
         * \brief Moves the robot to the start of the maze.
         */
        static void ackReset();
};

}  // namespace fp
