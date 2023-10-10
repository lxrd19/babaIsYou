#include "direction.h"

Direction::Direction(int x, int y ) : m_x(x), m_y(y){};

Direction Direction::RIGHT = Direction(0, 1);
Direction Direction::UP = Direction(-1, 0);
Direction Direction::LEFT = Direction(0, -1);
Direction Direction::DOWN = Direction(1, 0);


Position Direction::operator+(const Position& pos){
    return Position(this->m_x+pos.getX(), this->m_y+pos.getY());
}

bool Direction::operator==(const Direction& other) const {
    return (m_x == other.m_x) && (m_y == other.m_y);
}

Direction Direction::generateDir(const std::string&  text){
    Direction res;
    if(!text.compare("RIGHT")){
        res = Direction::RIGHT;
    }else if(!text.compare("UP")){
        res = Direction::UP;
    }else if(!text.compare("LEFT")){
        res = Direction::LEFT;
    }else if(!text.compare("DOWN")){
        res = Direction::DOWN;
    }
    return res;
}
