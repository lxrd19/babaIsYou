#ifndef METAL_H
#define METAL_H
#include "element.h"
/**
 * @brief The Metal class
 */
class Metal : public Element
{
public:
    /**
     * @brief Metal Constructs a Metal object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Metal(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction m_dir = Direction::RIGHT;
};

#endif // METAL_H
