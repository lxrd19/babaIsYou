#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include <vector>
#include <memory>
#include "Box.h"
#include "Position.h"
#include "Element.h"
#include "RuleElement.h"
#include "Direction.h"

/**
 * @brief The ObjectManager class Representes all the features of each item of the game
 */
class ObjectManager{
public:

    /**
     * @brief ObjectManager constructor of ObjectManager
     * @param board board of the game, it is actually an observer
     */
    ObjectManager(const std::vector<std::vector<Box*>>& board);
    /**
     * @brief push push the object at the given position in the given direction
     * @param pos the position of the material to push
     * @param dir the direction where to move the object
     */
    void push(const Position& pos, const Direction& dir);
    /**
     * @brief removePlayer removes the given player from the board, this method should be called when the player move to the goop,
     * or to the lava
     * @param pos the position the position of the player
     */
    void removePlayer(const Position& pos);
    /**
     * @brief canBePush checks if the given element at the given position can be pushed, this depens on the state of the  rule
     * that command the  material to push
     * @param el the element to push
     * @param pos the actual position of the material
     * @return true if the material can be push
     */
    bool canBePush(const Element& el, const Position& pos);
    /**
     * @brief move move the material at the given position
     * @param pos the position where to move the object
     * @param dir the direction where to move the object
     */
    void move(const Position& pos,  const Direction& dir);
    /**
     * @brief getElementAtPos return the element at the given position
     * @param pos the position of the element
     * @return the element at the given position
     */
    Element& getElementAtPos(const Position& pos);
    /**
     * @brief findeAllMaterial Returns all the positions of the given element on the board
     * @param el Element the element which positions is searched
     * @return the Element which positions should be find on the board
     */
    std::vector<Position*>& findeAllMaterial(const Element& el);

    /**
     * @brief isValidRule verify if the rule at the given position is valid, rule is valid if the element, the connector, effect
     * is on the same row or the same column
     * @param pos the position the position of the rule to check
     * @return true if the rule is valid
     */
    bool isValidRule(const Position& pos);
    /**
     * @brief  updateAllState change all the state of the material at  the given position
     * @param  positions the positions to update
     * @param  state the new state of the material to update
     */
    void updateAllState(std::vector<Position*> positions, bool state);
    /**
     * @brief getTarget Returns all the position of the target that the player should reach to win the level, depends on the rule that contain
     * win as effect
     * @return positions of all the target
     */
    const std::vector<Position*>& getTargetPositions()const;

    /**
     * @brief addTarget add position of the new target to the current list of position, depends on the rule that contain win
     * @param  the position of the new target
     */
    void addTarget(const Position*) const;
private:
    /**
     * @brief board the board of the game
     */
    std::vector<std::vector<Box*>> board;
    /**
     * @brief targets positions of all the target
     */
    std::vector<Position*> targetsPositions;
};

#endif // OBJECTMANAGER_H
