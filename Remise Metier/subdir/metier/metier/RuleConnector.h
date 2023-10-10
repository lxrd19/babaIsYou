#ifndef RULECONNECTOR_H
#define RULECONNECTOR_H
#include "Connector.h"
#include "Position.h"
#include "Direction.h"

/**
 * @brief The RuleConnector class The connector of a rule
 */
class RuleConnector {

public:
    /**
     * @brief RuleConnector constructor of the connector
     * @param connector the connector
     * @param pos the position
     * @param dir the direction where to move the connector
     */
    RuleConnector(const Connector& connector, const Position& pos, const Direction& dir);
    /**
     * @brief getConnector returns the connector of a rule
     * @return connector
     */
    const Connector& getConnector() const;
    /**
     * @brief getPosition returns the position of the connector
     * @return the position
     */
    const Position& getPosition() const;
    /**
     * @brief getDirection the direction where the connector can be move
     * @return the direction
     */
    const Direction& getDirection() const;

private:
    /**
     * @brief connector the connector
     */
    Connector& connector;
    /**
     * @brief pos position of the connector
     */
    Position& pos;
    /**
     * @brief dir the direction where connector can be moved
     */
    Direction& dir;
};

#endif // RULECONNECTOR_H
