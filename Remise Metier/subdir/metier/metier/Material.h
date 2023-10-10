#ifndef MATERIAL_H
#define MATERIAL_H
#include "Direction.h"
#include "GameObject.h"

class Position;
/**
 * @brief The Material class This class represent an item  of the board, Material is also game object
 */
class Material : GameObject{
public :
    /**
     * @brief Material Constructor of Material
     * @param Element the actual element of the material
     * @param Direction  the direction where the material can be move
     * @param Position the actual position on the board
     * @param state the state of the material
     */
    Material(const Element&, const ObjectState& state, const Direction& = Direction::RIGHT, const Position* = nullptr);
    /**
     * @brief getDirection returns the direction where the material can be moved
     * @return the direction
     */
    const Direction& getDirection() const;
    /**
     * @brief getElement returns the element of the material
     * @return the element
     */
    const Element& getElement() const;

    /**
     * @brief getPosition returns the position of the material on the board
     * @return the position
     */
    const Position& getPosition()const;
    /**
     * @brief getState return  the actual state of the material, it can be the fact that the material can be
     * pushed,  traversed or if it is destroyed.
     * @return the state of the material
     */
    const ObjectState& getState() const;

private:
    /**
     * @brief element of the material
     */
    Element element;
    /**
     * @brief dir the direction where it can move, right by default
     */
    Direction dir ;
    /**
     * @brief pos the actual of the material
     */
    Position* pos;
    /**
     * @brief state state of the material
     */
    ObjectState state;
};

#endif // MATERIAL_H
