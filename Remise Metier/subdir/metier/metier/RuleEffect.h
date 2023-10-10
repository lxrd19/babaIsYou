#ifndef RULEEFFECT_H
#define RULEEFFECT_H
#include "Effect.h"
#include "Position.h"
#include "Direction.h"

/**
 * @brief The RuleEffect class the effect of the rule
 */
class RuleEffect {
public:
    /**
     * @brief RuleEffect constructor of the effect
     * @param effect the effect
     * @param pos the position
     * @param dir the direction where to move the effect
     */
    RuleEffect(const Effect& effect, const Position& pos, const Direction& dir);
    /**
     * @brief getEffect returns the effect of a rule
     * @return effect
     */
    const Effect& getEffect() const;

    /**
     * @brief getPosition returns the position of the effect
     * @return the position
     */
    const Position& getPosition() const;
    /**
     * @brief getDirection the direction where the effect can be move
     * @return the direction
     */
    const Direction& getDirection() const;
private:
    /**
     * @brief effect the effect
     */
    Effect& effect;
    /**
     * @brief pos position of the effect
     */
    Position& pos;
    /**
     * @brief dir the direction where effect can be moved
     */
    Direction& dir;
};

#endif // RULEEFFECT_H
