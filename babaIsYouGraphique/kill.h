#ifndef KILL_H
#define KILL_H
#include "effect.h"
/**
 * @brief The Kill class
 */
class Kill : public Effect
{
public:
    /**
     * @brief Kill Constructs a kill object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Kill(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction m_dir = Direction::RIGHT;
};

#endif // KILL_H
