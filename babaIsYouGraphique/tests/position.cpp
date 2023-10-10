#include "position.h"

int Position::getX()const{
    return x;
}

int Position::getY()const{
    return y;
}



bool Position::operator==(const Position & other)const{
    return this->x == other.x && this->y == other.y;
}
Position::Position(int x, int y) : x(x), y(y){}
