#ifndef YOU_H
#define YOU_H

#include "effect.h"
/**
 * @brief The You class
 */
class You : public Effect
{
public:
    /**
     * @brief You Constructs a You object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    You(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction dir = Direction::RIGHT;
};

#endif // YOU_H
