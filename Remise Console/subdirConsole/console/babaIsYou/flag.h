#ifndef FLAG_H
#define FLAG_H
#include "element.h"
#include "direction.h"

/**
 * @brief The Flag class
 */
class Flag : public Element
{
public:
    /**
     * @brief Flag Constructs a flag object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Flag(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction dir =  Direction::RIGHT;
};

#endif // FLAG_H
