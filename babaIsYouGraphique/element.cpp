#include "element.h"

Element::Element(const std::string& name, const Direction &dir) : Composant(name, dir){}

std::string Element::getName(){
    return Composant::getName();
}

Direction Element::getDir(){
    return Composant::getDir();
}
