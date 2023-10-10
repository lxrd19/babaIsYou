#ifndef STOP_H
#define STOP_H

#include "direction.h"
#include "effect.h"
/**
 * @brief The Stop class
 */
class Stop : public Effect
{
public:
    /**
     * @brief Stop Constructs a Stop object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Stop(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction m_dir = Direction::RIGHT;
};

#endif // STOP_H
