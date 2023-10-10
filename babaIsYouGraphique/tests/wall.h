#ifndef WALL_H
#define WALL_H


#include "direction.h"
#include "element.h"
/**
 * @brief The Wall class
 */
class Wall : public Element
{
public:
    /**
     * @brief Wall Constructs a Wall object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Wall(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction m_dir = Direction::RIGHT;
};

#endif // WALL_H
