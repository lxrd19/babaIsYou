#ifndef RULECOMPOSANT_H
#define RULECOMPOSANT_H
#include "Element.h"
#include "Position.h"

class RuleComposant{
public:
    RuleComposant(const Element&, const Position&);
protected:
    virtual const Element& getName() const;
    virtual const Position& getPosition() const;
    virtual void setPosition(const Position&);

private:
     Element& name;
     Position& pos;
};

#endif // RULECOMPOSANT_H
