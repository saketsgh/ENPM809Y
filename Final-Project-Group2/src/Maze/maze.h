/**
 * @file Maze.h
 * @brief Final Project: Robot Path-planning and simulation using Micro-Mouse Simulator (MMS).
 *
 * File Description: This header file contains Maze class which reads the maze from MMS
 * and stores it in a c++ vector representation of a maze.
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
 *
 * @bug No known bugs.
 * @date 11-18-2019
 *
 */

#pragma once
#include <string>
#include <vector>
#include "../API/api.h"

//!  A Maze class.
/*! A Maze class which has all the basic functionalities for manipulating and reading the maze.
 * The maze is represented as a 2-D string vector of size obtained from the MMS API.
 * Each cell is a string containing four characters, each signifying a direction in the order of "nesw".
 * Where n --> north
 *       e --> east
 *       s --> south
 *       w --> west
 * At the initialization of the maze, all cells are assigned "0000", which means that they are unexplored.
 * Once each cell is visited and updated, the characters are changed depending on the status of the wall in the given direction.
 * So, '1' --> for no wall or free way
 *     '2' --> when wall is present.
 *
 * For example, when for a given cell we have a string "1212", then it means the following:
 * First character is '1' --> no wall in north.
 * Second character is '2' --> wall is present in east.
 * Third character is  '1' --> no wall in south.
 * Fourth character is '2' --> wall is present in west.
 *
 * The directions mentioned here are with respect to the cell and not the robot, which are as follows:
 *                           N
 *                           /\
 *                           ||
 *                           ||
 *                   W<--------------->E
 *                           ||
 *                           ||
 *                           \/
 *                            S
 *
 *
 *
 *
 */

namespace fp {

class Maze {
    public:
        //!  A constructor
        /*!  The constructor which creates a vector representation of the maze, of size 16X16. */
        Maze(int height=fp::API::mazeHeight(), int width=fp::API::mazeWidth()) :
            maze_(height, std::vector<std::string>(width, "0000")),
            width_{width},
            height_{height} {
        }

        //! A destructor
        ~Maze() {

        }

        ///////////////////////////////////////////////////////////////////////
        // Method Prototypes - Functions for manipulating and reading the maze:
        ///////////////////////////////////////////////////////////////////////

        //! A prototype for converting the y-coordinate in
        //! accordance to the vector format of addressing the cell.
        /*!
         * \param y the y-coordinate according to the maze representation in the MMS.
         * \return the y-coordinate in accordance with the vector format of addressing the cell.
         */
        int convert2MazeY(int y);

        //! A prototype function which checks for the presence of the
        //! wall in a given direction.
        /*!
         * \param x the x-coordinate of the robot in the maze.
         * \param y the y-coordinate of the robot in the maze.
         * \param direction the direction in which the presence of the wall is to be checked.
         * \param roboDir the current direction of the robot in the maze.
         * \return true or false depending on the presence of the wall in a given direction.
         */
        bool isWall(int x, int y, char direction, char roboDir);

        //! A prototype function which sets the wall in the specified direction
        //! and updates it to the MMS and also the maze vector.
        /*!
         * \param x the x-coordinate of the robot in the maze.
         * \param y the y-coordinate of the robot in the maze.
         * \param direction the direction in which the wall is to be set.
         */
        void setWall(int x, int y, char direction);

        //! A prototype function which clears or specifies a free way in
        //! given direction and updates the same with MMS and the maze vector.
        /*!
         * \param x the x-coordinate of the robot in the maze.
         * \param y the y-coordinate of the robot in the maze.
         * \param direction the direction in which there is a free way or no wall present.
         */
        void clearWall(int x, int y, char direction);

        //! A prototype function which updates the given cell of the maze
        //! by checking all the four directions and using the above prototypes.
        /*!
         * \param x the x-coordinate of the robot in the maze.
         * \param y the y-coordinate of the robot in the maze.
         * \param roboDir the current direction of the robot in the maze.
         */
        void updateCell(int x, int y, char roboDir);

        void printCell(int x, int y);

        ///////////////////////////////////////////////////////////////////////
        // Accessors/getters - access width and height of the maze:
        ///////////////////////////////////////////////////////////////////////

        //! Accessor
        /*!
         * \brief  A prototype for getting the width of the maze.
         * \return the width of the maze.
         */
        int getWidth() {
            return width_;
        }

        //! Accessor
        /*!
         * \breif A prototype for getting the height of the maze.
         * \return the height of the maze.
         */
        int getHeight() {
            return height_;
        }


        ///////////////////////////////////////////////////////////////////////
        // Public attributes of the maze:
        ///////////////////////////////////////////////////////////////////////

        //Attribute - Maze in vector representation.
        std::vector<std::vector<std::string>> maze_;

    private:

        ///////////////////////////////////////////////////////////////////////
        // Private attributes of the maze:
        ///////////////////////////////////////////////////////////////////////

        //Attribute - Width of the maze.
        int width_;

        //Attribute - Height of the maze.
        int height_;
};

}  // namespace fp
