#ifndef PUSH_H
#define PUSH_H

#include "effect.h"
/**
 * @brief The Push class
 */
class Push : public Effect
{
public:
    /**
     * @brief Push Constructs a Push object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Push(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction dir = Direction::RIGHT;
};

#endif // PUSH_H
