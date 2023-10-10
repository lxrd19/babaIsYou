#ifndef EFFECT_H
#define EFFECT_H
#include <iostream>
#include <map>
#include "composant.h"

/**
 * @brief The Effect enum
 * The effect of Rule, these are all the of the top 5 level of the game
 */
class Effect : public Composant{
public:
    /**
     * Default constructor for the Effect class.
     */
    Effect() = default;
    /**
         * Constructs an Effect object with the specified name and direction.
         * @param name The name of the Effect object.
         * @param dir The direction of the Effect object.
    */
    Effect(const std::string& name, const Direction& dir);

private:
    std::string m_name;
    Direction m_dir = Direction::RIGHT;
};


#endif // EFFECT_H
