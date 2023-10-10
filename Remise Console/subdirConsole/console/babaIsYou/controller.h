#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "position.h"
#include "direction.h"

/**
 * Forward declaration of BoardView the compiler should know about it
 */
class BoardView;
/**
 * Forward declaration of Game the compiler should know about it
 */
class Game;
/**
 * Forward declaration of IObserver the compiler should know about it
 */
class IObserver;
/**
 * @brief The Controller class verify the validity of all
 * entered by the user
 */
class Controller{
public:

    /**
     * @brief Controller Creates a controller object
     * @param game the model
     * @param board the board of the game which
     * is actually the view
     */
    Controller(Game * game = nullptr, BoardView* board = nullptr);

    /**
     * @brief registerObserver Adds one more observer to the
     * list of observers
     *
     * @param obs the new observer to add to the list
     */

    void registerObserver(const IObserver* obs = nullptr);
    /**
     * @brief initGameBoard Initializes the board
     *
     * @param The path of the file that is use to fill the board
     */
    void initGameBoard(const std::string&);

    /**
     * @brief verifyPos Checks the validity of a position given by the user
     * @param  the position to verify
     */
    void verifyPos(const Position&);

    /**
     * @brief verifyDirection Checks the validity of a direction given by the user,
     * all valid direction are given by the enum Direction
     * @param  the direction to verify
     */
    void verifyDirection(const Direction&);

    /**
     * @brief push Allows the current player to push on item at a given position
     * on the board following the given direction
     * @param pos the position of the item to push
     * @param dir the direction where the item should be pushed
     */
    void push(const Position& pos, const Direction& dir);

private:
    /**
     * @brief view the board of the game which is the observer
     */
    BoardView* view;

    /**
     * @brief model which will notify all observers
     */
    Game* model;
};

#endif // CONTROLLER_H
