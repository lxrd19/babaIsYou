#ifndef PLAYER_H
#define PLAYER_H
#include "Position.h"
#include "Direction.h"
#include "Element.h"
#include <memory>

/**
 * @brief The Player class Represents the player of the game, it' s  baba by default
 */
class Player{
public:
    /**
     * @brief pushObject push
     * @param pos push a material at a given postion by a direction
     * @param dir the direction where to push the object
     */
    void pushObject(const Position& pos, const Direction& dir);
    /**
     * @brief Player Contructor of a player
     * @param dir direction where to move the player
     * @param el the element that is the actual player
     * @param pos the position of the player
     */
    Player(const Direction& dir, const Element& el, const Position& pos);


    /**
     * @brief canMove checks if the player can move, this depends on the rule that contains you as effect
     * @return true if the player can move
     */
    bool canMove();
    /**
     * @brief moveTo moves the player at the given position, following a given direction
     * @param  pos the position  of the player
     * @param dir the direction where the player will be move
     */
    void moveTo(const Position& pos, Direction& dir);
    /**
     * @brief setMovable update the movable state of the player
     * @param state the new state
     */
    void setMovable(bool state);
    /**
     * @brief getPosition return the position of the player
     * @return the current position of the player
     */
    const Position& getPosition() const;
    /**
     * @brief getDirection return the actual direction of the player, where the player can be moved
     * @return the direction
     */
    const Direction& getDirection() const;
    /**
     * @brief getElement return the actual element that represent the player on board
     * @return the element
     */
    const Element& getElement() const;
private:
    /**
     * @brief isMovable checks if the player can be moved
     */
    bool isMovable = true;
    /**
     * @brief dir the direction where the player can be moved
     */
    Direction dir;
    /**
     * @brief element the element that represent the player
     */
    Element element;
    /**
     * @brief pos the position of the player
     */
    Position pos;
};

#endif // PLAYER_H
