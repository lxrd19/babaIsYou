#ifndef GAME_H
#define GAME_H
#include <vector>
#include <memory>
#include "Box.h"
#include "ISubject.h"
#include "IObserver.h"
#include "FileManager.h"
#include "ObjectManager.h"
#include "Direction.h"
/**
 *@brief foarward declaration of class Player
 */
class Player;
/**
 *@brief forward declaration of class BoardView
 */
class BoardView;

/**
 * @brief The Game class Represents all the features of the game,
 * this class is a subject and will notify the view after updating data
 */
class Game : public ISubject{
public:
    /**
     * @brief destructor of Game
     */
    ~Game();
    /**
     * @brief Game Constructor of Game
     * @param board the board
     * @param objectManager use to manage features of objects on the board
     * @param fileManager use to manage the file that are used to update the levels
     * @param player the current player
     */
    Game(const std::vector<std::vector<Box*>>& board,const ObjectManager& objectManager, const FileManager& fileManager, const Player* = nullptr);
    /**
     * @brief attach add one more observers in the list of observers if it's not yet in the list
     */
    void attach(IObserver*)override;
    /**
     * @brief detach remove the guven observer from the list
     */
    void detach(IObserver*)override;
    /**
     * @brief notify
     */
    void notify() override;
    /**
     * @brief changePlayer change the current player with all occurrences of the given element on the board
     * @param the Element that should be the new player
     */
    void changePlayer(const Element&);
    /**
     * @brief receiveDirection should be called after check of the given direction for stuff like
     * moving objects or the actual player on the board
     * @param dir the direction where to move
     */
    void receiveDirection(const Direction& dir);
    /**
     * @brief checkPosition should be called after check of the given position for stuff like
     * moving objects or the actual player on the board
     * @param pos the direction where to move
     */
    bool checkPosition(const Position& pos);
    /**
     * @brief isWin checks if the actual level is won, if this is the case it will change the actual level
     * @return true if the level is won
     */
    bool isWin() const;
    /**
     * @brief getBoard return the board of the game
     * @return the board
     */
    const std::vector<std::vector<Box*>>& getBoard()const;
    /**
     * @brief getFileManager return the file manager the should be use to update the level
     * @return the filManager
     */
    const FileManager& getFileManager() const;
    /**
     * @brief getGameObject proccess all manipulations of all of the game objects
     * @return gameObject
     */
    const GameObject& getGameObject() const;

    /**
     * @brief nextLevel update the current level in fileManager
     */
    void nextLevel() const;
private:
    /**
     * @brief objectManager process all data of all the game objects
     */
    const ObjectManager& objectManager;
    /**
     * @brief fileManager process all the file that are use to update the level
     */
    const FileManager& fileManager;
    /**
     * @brief player the current player
     */
    Player* player;
    /**
     * @brief observers observers that will update the board
     */
    std::vector<BoardView*> observers;
    /**
     * @brief board the board of the game
     */
    std::vector<std::vector<Box*>> board;
};

#endif // GAME_H
