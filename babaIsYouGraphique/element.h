#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <map>
#include <utility>
#include "composant.h"

/**
 * @brief The Element enum the name of one item of the game, these are all the name of the top 5
 * level of the game
 */

class  Game;
class Element : public Composant {
public:
    /**
     * Default constructor for the Element class.
    */
    Element() = default;

    /**
         * Constructs an Element object with the specified name and direction.
         * @param name The name of the Element object.
         * @param dir The direction of the Element object.
    */
    Element(const std::string& name, const Direction& dir);

    virtual std::string getName();
    virtual Direction getDir();


private:
};

#endif // ELEMENT_H
