#ifndef LAVA_H
#define LAVA_H

#include "element.h"
/**
 * @brief The Lava class
 */
class Lava : public Element
{
public:
    /**
     * @brief Lava Constructs a Lava object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Lava(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction m_dir = Direction::RIGHT;
};

#endif // LAVA_H
