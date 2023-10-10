#ifndef ROCK_H
#define ROCK_H


#include "direction.h"
#include "element.h"
/**
 * @brief The Rock class
 */
class Rock : public Element
{
public:
    /**
     * @brief Rock Constructs a rock object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Rock(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction m_dir = Direction::RIGHT;
};

#endif // ROCK_H
