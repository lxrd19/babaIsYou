#ifndef COMPOSANT_H
#define COMPOSANT_H
#include "direction.h"
#include  <iostream>
#include <memory>
#include <vector>

class  Box;

class Composant{

public:
    /**
       * Default constructor for the Composant class.
    */
    Composant() = default;
    /**
        * Constructs a Composant object with the specified name and direction.
        * @param name The name of the Composant object.
        * @param dir The direction of the Composant object (default is Direction::RIGHT).
    */
    Composant(const std::string& name,  const Direction& dir= Direction::RIGHT);
    /**
        * Returns the name of the Composant object.
        * @return The name of the Composant object as a const string reference.
    */
    const std::string getName()const;

    const Direction getDir()const;

    /**
        * Compares two Composant objects for equality.
        * @param other The other Composant object to compare with.
        * @return True if the Composant objects are equal, false otherwise.
    */
    bool operator==(const Composant& other) const;

private:
    std::string m_name;
    Direction m_dir =  Direction::RIGHT;

};



#endif // COMPOSANT_H
