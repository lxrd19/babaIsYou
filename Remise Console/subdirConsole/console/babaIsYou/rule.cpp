#include "rule.h"

Rule::Rule(const std::string& element, const std::string& connector, const std::string& effect)
    : element(element), connector(connector), effect(effect) {}

std::string Rule::getElement() const { return element; }
std::string Rule::getConnector() const { return connector; }
std::string Rule::getEffect() const { return effect; }
