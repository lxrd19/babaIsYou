#ifndef DIRECTION_H
#define DIRECTION_H
#include "position.h"
#include <iostream>


class Direction {
public :
    static  Direction RIGHT;
    static  Direction UP;
    static  Direction LEFT;
    static  Direction DOWN;
    /**
         * Adds a Position object to the current Direction object.
         * @param pos The Position object to add.
         * @return A new Position object resulting from the addition.
    */
    Position operator+(const Position& pos);
    /**
         * Generates a Direction object based on the input text.
         * @param text The text representing the direction (e.g. "UP", "DOWN", "LEFT", "RIGHT").
         * @return A Direction object corresponding to the input text.
    */
    static Direction generateDir(const std::string&  text);
    /**
         * Compares two Direction objects for equality.
         * @param other The other Direction object to compare with.
         * @return True if the Direction objects are equal, false otherwise.
    */
    bool operator==(const Direction& other) const;
    /**
     * @brief Converts the object to a string representation.
     *
     * @return A string representation of the object.
    */
    std::string toString();

private :
    int m_x;
    int m_y;
    Direction(int x, int y);
    Direction() = default;
};



#endif // DIRECTION_H
