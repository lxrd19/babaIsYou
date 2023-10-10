#ifndef GRASS_H
#define GRASS_H
#include "element.h"
/**
 * @brief The Grass class
 */
class Grass : public Element
{
public:
    /**
     * @brief Grass Constructs a Grass object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Grass(const std::string& name, const Direction& dir);
//    std::string getName();
//    Direction  getDir();
private:
    std::string  m_name;
    Direction m_dir = Direction::RIGHT;
};

#endif // GRASS_H
