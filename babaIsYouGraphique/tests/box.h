#ifndef BOX_H
#define BOX_H
#include "composant.h"
#include <memory>
#include <vector>
#include <algorithm>

class Box{
public:
    /**
     * @brief Box
     * Create a Box of the board.
     * Can contain several object of the game.
     */
    Box() = default;

    /**
     * @brief addObject Adds item to the box
     *
     * @param obj the object to add to the box
     */
    void addObject(Composant comp);

    void removeLastObject();

    void removeFront();
    /**
     * @brief removeObject Removes item of the box
     * @param obj the object to remove
     */
    //    void removeObject(GameObject* obj);

    /**
     * @brief getObjects return all object on the  current box
     * @return list of the object.
     */
    const std::vector<Composant>&  getObjects() const;
    bool isEmpty() const;

    /**
     * @brief isOccupied checks if the current box contain one item
     * @return true if the box contain one item
     */
    bool isOccupied()const;
    /**
         * Compares two Box objects for equality.
         * @param other The other Box object to compare with.
         * @return True if the Box objects are equal, false otherwise.
         */
    bool operator==(const Box& other);
    /**
        * Replaces the objects in the Box with a new set of objects.
        * @param newObjects A vector of Composant objects to set in the Box.
    */
    void setObjects(const std::vector<Composant>& newObjects);
    /**
        * Removes all objects from the Box.
     */
    void clearObjects();
    /**
        * Returns a reference to the vector of Composant objects in the Box.
        * @return A reference to the vector of Composant objects.
    */
    std::vector<Composant>& getObjects();
    void removeComponent(Composant toRemove);
private:
    /**
     * @brief occupied checks if the box contain one item
     */
    bool occupied = false;

    /**
     * @brief objects all the item of the box
     */

    std::vector<Composant> objects;
    /**
     * Determines if a given Composant object is a rule component.
     * A rule component is an object with specific names or name prefixes.
     * @param obj The Composant object to check.
     * @return True if the object is a rule component, false otherwise.
     */
    bool isObjectRuleComponent(const Composant& obj) {
        const std::string& name = obj.getName();
        if (name == "push" || name == "stop" || name == "is" || name == "you" ||
                name == "win" || name == "best" || name.substr(0, 5) == "text_") {
            return true;
        }
        return false;
    }
};

#endif // BOX_H
