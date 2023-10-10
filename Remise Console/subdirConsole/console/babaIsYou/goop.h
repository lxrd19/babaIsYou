#ifndef GOOP_H
#define GOOP_H
#include "element.h"

/**
 * @brief The Goop class
 */
class Goop : public Element
{
public:
    /**
     * @brief Goop Constructs a goop object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Goop(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction dir =  Direction::RIGHT;

};

#endif // GOOP_H
