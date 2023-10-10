#ifndef BABA_H
#define BABA_H
#include "element.h"
/**
 * @brief The Baba class
 */
class Baba : public Element{
public:
    /**
     * @brief Baba Constructs a Baba object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Baba(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction m_dir =  Direction::RIGHT;
};

#endif // BABA_H
