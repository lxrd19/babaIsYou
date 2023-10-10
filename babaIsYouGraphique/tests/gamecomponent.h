#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H


#include "direction.h"

class Game;

class GameComponent {
public:
    virtual ~GameComponent() = default;
    virtual void apply(Game& game, Direction direction) = 0;
};


#endif // GAMECOMPONENT_H
