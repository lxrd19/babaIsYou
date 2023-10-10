#ifndef RULE_H
#define RULE_H
#include <iostream>
/**
 * @brief The Rule class
 */
class Rule {
public:

    /**
     * @brief Rule Contructs Rule object with element connector and effect
     * @param element the element
     * @param connector the connector
     * @param effect the effect
     */
    Rule(const std::string& element, const std::string& connector, const std::string& effect);
    /**
     * @brief Gets the element of the rule
     * @return The element of the rule as a string
    */
    std::string getElement() const;
    /**
     * @brief Gets the effect of the rule
     * @return The effect of the rule as a string
    */

    std::string getEffect() const ;
    /**
     * @brief Gets the cnnector of the rule
     * @return The connector of the rule as a string
    */
    std::string getConnector() const;

private:
    std::string element;
    std::string connector;
    std::string effect;
};

#endif // RULE_H
