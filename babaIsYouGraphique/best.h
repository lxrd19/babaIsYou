#ifndef BEST_H
#define BEST_H
#include "element.h"
/**
 * @brief The Best class
 */
class Best : public Element{
public:
    /**
     * @brief Best Constructs a Best object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Best(const std::string& name, const Direction&  dir);
private:
    std::string  m_name;
    Direction m_dir = Direction::RIGHT;
};

#endif // BEST_H
