#ifndef BOARDVIEW_H
#define BOARDVIEW_H
#include "Controller.h"
#include "IObserver.h"
#include <memory>
#include <vector>

/**
 *@brief forward declaration of Box the compiler should know about it
 */
class Box;

/**
 * @brief The BoardView class
 * The board of the game, this class is an
 * observer and will be updated by Game
 */
class BoardView : public IObserver{
public:

    /**
     * @brief Destructor for Boardview
     */
    ~BoardView();

    /**
     * @brief BoardView
     * constructor of BoardView
     * @param control controller which will validate all input of the view
     */
    BoardView(const Controller& control);

    /**
     * @brief update
     * this method is called by all subject when change
     * happened in the game
     * @param game the subject
     */
    void update(const ISubject& game) override;

    /**
     * @brief print print the board
     * @param the board
     */

    void print(std::vector<std::vector<Box*>>& board);

    /**
     * @brief askDirection
     * Ask the user a direction where to move
     * the object on the board
     * @return the direction
     */
    const Direction& askDirection()const;
    /**
     * @brief askPosition
     * Ask the user a position where to move
     * the object on the board
     * @return the position
     */
    const Position& askPosition()const;

    /**
     * @brief isInside checks if an item is on the board
     * @param pos the position to check
     * @return true if the object is on the board
     */
    bool isInside(const Position& pos) const;

private:
    /**
     * @brief controller verify  the validity of user input
     */
    Controller controller;
};

#endif // BOARDVIEW_H
