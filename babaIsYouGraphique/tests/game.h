#ifndef GAME_H
#define GAME_H
#include <vector>
#include <memory>
#include "box.h"
#include "controller.h"
#include "irule.h"
#include "isubject.h"
#include "iobserver.h"
#include "filemanager.h"
#include "direction.h"
#include "managedata.h"
#include <sstream>
#include <unordered_set>
#include <map>
#include <stdexcept>

class ManageData;
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
    Game(const std::vector<std::vector<Box>> &board);
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
    void notify()
        override;
    /**
     * @brief changePlayer change the current player with all occurrences of the given element on the board
     * @param the Element that should be the new player
     */
    void changePlayer(const Composant&);
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
    const std::vector<std::vector<Box>>& getBoard()const;
    /**
     * @brief getFileManager return the file manager the should be use to update the level
     * @return the filManager
     */
    const FileManager& getFileManager() const;

    /**
     * @brief nextLevel update the current level in fileManager
     */
    void nextLevel() const;

    /**
     * @brief Handles user input and executes appropriate actions.
     * @param input The user input as a string.
     */
    void handleUserInput(const std::string& input);
    /**
     * @brief Retrieves the X position of the player.
     * @return The X position of the player.
     */
    int getPlayerX();
    /**
     * @brief Retrieves the Y position of the player.
     * @return The Y position of the player.
     */
    int getPlayerY();
    /**
     * @brief Executes the given command and notifies observers of the change.
     * @param command The command to be executed.
     */
    void executeCommandAndNotify(std::shared_ptr<ICommand> command);

    /**
     * @brief Checks if the given Position is within the game board boundaries.
     * @param pos The Position to be checked.
     * @return True if the Position is inside the game board, false otherwise.
     */
    bool isInside(const Position& pos) const ;
    /**
     * @brief Checks if the given name corresponds to a rule component.
     * @param name The name to be checked.
     * @return True if the name corresponds to a rule component, false otherwise.
     */
    bool isRuleComponantName(const std::string& name);
    /**
     * @brief Determines if a Box is applicable to the given effect.
     * @param box The Box to be checked.
     * @param effect The effect to be tested.
     * @return True if the Box is applicable to the effect, false otherwise.
     */
    bool isBoxApplicable(const Box&  box, const std::string& effect) const;

    /**
     * @brief Get the pushable components in a specified direction from a starting position.
     *
     * @param startX The x-coordinate of the starting position.
     * @param startY The y-coordinate of the starting position.
     * @param dir The direction in which to search for pushable components.
     * @return std::vector<std::pair<Composant, Position>> A vector of pushable components and their positions.
     */
    std::vector<std::pair<Composant, Position> > getPushableComponentsInDirection(int startX, int startY, Direction dir);

    /**
     * @brief Get the player's Composant object.
     *
     * @return Composant The player Composant.
     */
    Composant getPlayer();
    /**
     * @brief Add components to the game board at specified positions.
     *
     * @param componentsPositions A vector of components and their positions to be added to the board.
     */
    void addComponentsToBoard(const std::vector<std::pair<Composant, Position>>& componentsPositions);


    /**
     * Returns the current controller object.
     * @return The current controller object.
     */
    Controller getController(){
        return controller;
    }
    /**
     * @brief Get the win position object.
     *
     * @return A vector reference to the win positions.
    */
    std::vector<Position>& getWinPosition();
    /**
     * @brief Sets a new position.
     *
     * @param toSet A reference to the vector of positions to be set.
     * @param newPositions A reference to the vector of new positions.
    */
    std::vector<Position>& getPushPosition();
    /**
     * @brief Get the rule objects.
     *
     * @return A reference to the vector of unique pointers to Irule objects.
    */
    std::vector<Position>& getStopPosition();
    std::vector<Position>& getYouPosition();
    std::vector<Position>& getKillPosition();
    std::vector<Position>& getSinkPosition();
    std::vector<Position>& getBestPosition();

    void setPositions(std::vector<Position> &toSet, std::vector<Position> &newPositions);
    std::vector<std::unique_ptr<Irule>>& getIrule();
    /**
     * @brief Applies all the rules to the game board.
    */
    void applyRules();

    /**
     * @brief Moves the player in the given direction.
     *
     * @param dir The direction to move the player.
    */
    void move(Direction dir);

    /**
     * @brief Removes certain components from the game board.
     *
     * @param pushableComponents A vector of pairs, each containing a Composant and a Position, representing components that can be pushed.
    */
    void removeFromBoard(const std::vector<std::pair<Composant, Position>>& pushableComponents);

    /**
     * @brief Applies the direction to the given components.
     *
     * @param componentsPositions A vector of pairs, each containing a Composant and a Position, representing components that can move.
     * @param dir The direction to apply.
    */
    void applyDirection(std::vector<std::pair<Composant, Position>>& componentsPositions, Direction& dir);
    /**
     * @brief Moves the player to a new position in a certain direction.
     *
     * @param pos The new position to move the player.
     * @param dir The direction to move the player.
    */
    void movePlayer(Position pos, Direction dir);
    /**
     * @brief Sets a new player.
     *
     * @param newPlayer The new player to be set.
    */
    void setPlayer(Composant newPlayer);
    /**
     * @brief Clears all positions.
    */
    void clearPositions();
    /**
     * @brief Handles the user's input.
     *
     * @param input The user's input.
    */
    void handleUserInputUpdated(const std::string& input);
    /**
     * @brief Adds a new rule component position.
    */
    void addRuleComponentPosition();
    /**
     * @brief Loads the game.
    */
    void load();
    /**
     * @brief Saves the game.
    */
    void save();
    /**
     * @brief Finds new rules based on the current state of the game.
    */
    void findNewRules();
private:
    std::vector<Position> pushPositions;
    std::vector<Position> youPositions;
    std::vector<Position> killPositions;
    std::vector<Position> sinkPositions;
    std::vector<Position> winPositions;
    std::vector<Position> stopPositions;
    std::vector<Position> bestPositions;
    std::vector<std::unique_ptr<Irule>> iRules;
    bool levelEnded = false;
    /**
     * @brief fileManager process all the file that are use to update the level
     */
    FileManager m_fileManager;
    /**
     * @brief player the current player
     */
    Composant player;

    ManageData m_manageData;

    /**
     * @brief observers observers that will update the board
     */
    std::vector<IObserver*> observers;
    /**
     * @brief board the board of the game
     */
    std::vector<std::vector<Box>> m_board;

    Controller controller;

    /**
     * @brief Checks if a given position exists in a vector of positions.
     *
     * @param positions A vector of positions to check.
     * @param givenPosition The position to look for.
     * @return true if the position exists in the vector.
     * @return false otherwise.
    */

    bool containsPosition(const std::vector<Position>& positions, const Position& givenPosition) {
        return std::find(positions.begin(), positions.end(), givenPosition) != positions.end();
    }

    /**
     * @brief Moves a set of positions in a given direction.
     *
     * @param toMove The positions to move.
     * @param dir The direction in which to move the positions.
     * @return A vector of the new positions after moving. If a stop position is encountered, an empty vector is returned.
    */
    std::vector<Position> moveToDirection(std::vector<Position> toMove, Direction dir){
        std::vector<Position> result;
        for(const auto& el : toMove){
            auto newPos = dir + el;
            if(containsPosition(stopPositions, newPos)){
                result.clear();
                break;
            }
            result.emplace_back();
        }
        return result;
    }

};

#endif // GAME_H
