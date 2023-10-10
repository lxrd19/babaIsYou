#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <iostream>
#include <map>
#include "composant.h"
#include "controller.h"
/**
 * @brief The Connector enum the connector of a rule.
 * it is the second element of a rule object.
 */
class Connector : public Composant{
public:

    /**
     * Constructs a Connector object with the specified name and direction.
     * @param name The name of the Connector object.
     * @param dir The direction of the Connector object.
     */
    Connector(const std::string& name, const Direction& dir);
    virtual void apply(Game& game, Direction dir) = 0;

private:
    std::string m_name;
    Direction m_dir = Direction::RIGHT;
};

#endif // CONNECTOR_H
