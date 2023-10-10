#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Element.h"
#include "ObjectState.h"

/**
 * @brief The GameObject class one item  of the board
 */
class GameObject{
public:
    /**
     * @brief GameObject Creates an objects on the  board
     * @param el the element of the item
     * @param state  the actual of the item
     */
    GameObject(const Element& el , const ObjectState& state);
    /**
     * @brief updatePushable utpdate the state of the item, it can make the item pushable, traversable, destroyable.
     * @param state  the new state
     */
    virtual void updatePushable(bool state);
private:
    /**
     * @brief type Type of the item, see enum Element
     */
    Element type;
    /**
     * @brief state the state of the item
     */
    ObjectState state;
};

#endif // GAMEOBJECT_H
