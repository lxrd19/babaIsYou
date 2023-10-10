#ifndef WIN_H
#define WIN_H
#include "effect.h"
/**
 * @brief The Win class
 */
class Win : public Effect
{
public:
    /**
     * @brief Win Constructs a Win object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Win(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction m_dir = Direction::RIGHT;
};

#endif // WIN_H
