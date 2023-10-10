#ifndef RULEELEMENT_H
#define RULEELEMENT_H
#include "Position.h"
#include "Element.h"
#include "Direction.h"


/**
 * @brief The RuleElement class the element of rule
 */
class RuleElement {
public:
    /**
     * @brief RuleElement the constructor of the element
     * @param element the element
     * @param pos the position
     * @param dir the directon where to move the element
     */
    RuleElement(const Element&, const Position&, const Direction&);
    /**
     * @brief getEffect returns the element of a rule
     * @return effect
     */
    const Element& getElement() const;
    /**
     * @brief getPosition returns the position of the element
     * @return the position
     */
    const Position& getPosition() const;
    /**
     * @brief getDirection the direction where the element can be move
     * @return the direction
     */
    const Direction& getDirection() const;

private:
    /**
     * @brief element the element
     */
    Element element;
    /**
     * @brief pos position of the element
     */
    Position pos;
    /**
     * @brief dir the direction where element can be moved
     */
    Direction dir;
};

#endif // RULEELEMENT_H
