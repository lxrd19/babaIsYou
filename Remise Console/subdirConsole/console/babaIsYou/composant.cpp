#include "composant.h"

Composant::Composant(const std::string& name, const Direction& dir) : m_name(name), m_dir(dir) {}

const std::string Composant::getName()const{
    return  m_name;
}
bool Composant::operator==(const Composant& other) const {
    return m_name == other.m_name;
}

