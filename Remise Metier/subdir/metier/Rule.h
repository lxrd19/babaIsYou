#ifndef RULE_H
#define RULE_H
#include "GameObject.h"
#include "RuleElement.h"
#include "RuleConnector.h"
#include "RuleEffect.h"

/**
 * @brief The Rule class Represents a rule on the board, is also consider ass GameObject
 */
class Rule : GameObject{
public:
    /**
     * @brief Rule  the constructor of Rule
     * @param element the element of the rule
     * @param connector the connector of the rule
     * @param effect the effect of the rule
     */
    Rule(const RuleElement& element, const RuleConnector& connector, const RuleEffect& effect);
    /**
     * @brief isValidRule Checks if the actual rule is valid, a rule is valid when it's element , connector and effect is on the
     * same column or row
     * @return true if the rule is valid
     */
    bool isValidRule();
    /**
     * @brief getElement Returns the Element of the actual rule
     * @return the element
     */
    const RuleElement& getElement() const;
    /**
     * @brief getEffect Returns the Effect of the actual rule
     * @return the effect
     */
    const RuleEffect& getEffect() const;
    /**
     * @brief getConnector Returns the Connector of the actual rule
     * @return the connector
     */
    const RuleConnector& getConnector() const;

private:
    /**
     * @brief element the element that is manipulate by the rule
     */
    RuleElement element;
    /**
     * @brief connector the connector that is manipulate by the rule
     */

    RuleConnector connector;
    /**
     * @brief effect the effect that is manipulate by the rule
     */

    RuleEffect effect;
};

#endif // RULE_H
