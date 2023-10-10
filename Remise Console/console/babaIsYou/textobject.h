#ifndef TEXTOBJECT_H
#define TEXTOBJECT_H
#include "element.h"

/**
 * @brief The TextObject class
 */
class TextObject :public Element
{

public:
    /**
     * @brief TextObject Constructs a TextObject object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    TextObject(const std::string& name , const Direction& dir);

private:
    std::string  m_name;
    Direction m_dir = Direction::RIGHT;
};


#endif // TEXTOBJECT_H
