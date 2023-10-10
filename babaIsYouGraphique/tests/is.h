#ifndef IS_H
#define IS_H


#include "connector.h"
#include "controller.h"
#include "direction.h"
/**
 * @brief The Is class
 */
class Is : public Connector
{
public:
    /**
     * @brief Is Constructs a is object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
//    void apply(Game& game, Direction dir) override;
    Is(const std::string& name,const Direction& dir);
private:
    std::string  m_name;
    Direction  m_dir = Direction::RIGHT;
};

#endif // IS_H
