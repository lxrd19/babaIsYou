#ifndef BOX_H
#define BOX_H
#include "GameObject.h"
#include <memory>
#include <vector>

class Box{
public:
    /**
     * @brief Box
     * Create a Box of the board.
     * Can contain several object of the game.
     */
    Box();

    /**
     * @brief addObject Adds item to the box
     *
     * @param obj the object to add to the box
     */
    void addObject(const GameObject& obj);

    /**
     * @brief removeObject Removes item of the box
     * @param obj the object to remove
     */
    void removeObject(const GameObject& obj);

    /**
     * @brief getObjects return all object on the  current box
     * @return list of the object.
     */
    const std::vector<GameObject*>& getObjects() const;

    /**
     * @brief isOccupied checks if the current box contain one item
     * @return true if the box contain one item
     */
    bool isOccupied()const;

private:
    /**
     * @brief occupied checks if the box contain one item
     */
    bool occupied = false;

    /**
     * @brief objects all the item of the box
     */
    std::vector<GameObject*> objects;
};

#endif // BOX_H
