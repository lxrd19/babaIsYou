#ifndef GAME_H
#define GAME_H
#include <vector>
#include <memory>
#include "box.h"
#include "controller.h"
#include "isubject.h"
#include "iobserver.h"
#include "filemanager.h"
#include "direction.h"
#include "rule.h"
#include <sstream>
#include <unordered_set>
#include <map>


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
    Game(const std::vector<std::vector<Box> > &board);
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
     * @brief getGameObject proccess all manipulations of all of the game objects
     * @return gameObject
     */
    //    const GameObject& getGameObject() const;

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
     * @brief Retrieves the Composant at a given Position.
     * @param pos The Position to query for the Composant.
     * @return The Composant at the given Position.
     */
    Composant getAt(const Position& pos);
    /**
     * @brief Checks if the given element is present in the game rules.
     * @param destElement The element to search for in the rules.
     * @return True if the element is found in the rules, false otherwise.
     */
    bool isElementInRules(const std::string& destElement) ;
    /**
     * @brief Moves a game object from a Position in a given Direction.
     * @param pos The starting Position of the game object.
     * @param dir The Direction to move the game object.
     */
    void move(const Position& pos, Direction& dir);
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
     * @brief Finds the current player and updates the internal state.
     */
    void findCurrentPlayer();
    /**
     * @brief Clears all objects within a given Box.
     * @param box The Box containing objects to be cleared.
     */
    void clearObjects(Box& box);
    /**
     * @brief Updates the current player's position and state.
     */
    void updateCurrentPlayer();
    /**
     * @brief Checks if the given name corresponds to a rule component.
     * @param name The name to be checked.
     * @return True if the name corresponds to a rule component, false otherwise.
     */
    bool isRuleComponantName(const std::string& name);
    /**
     * @brief Checks if all objects within a Box are rule components.
     * @param box The Box to be checked.
     * @return True if all objects within the Box are rule components, false otherwise.
     */
    bool areAllObjectsRuleComponents(const Box& box);
    /**
     * @brief Retrieves a reference to the Box at the given position.
     * @param x The X position of the Box.
     * @param y The Y position of the Box.
     * @return A reference to the Box at the given position.
     */
    Box& getBoxAtPosition(size_t x,  size_t y);
    /**
     * @brief Determines if a Box is applicable to the given effect.
     * @param box The Box to be checked.
     * @param effect The effect to be tested.
     * @return True if the Box is applicable to the effect, false otherwise.
     */
    bool isBoxApplicable(const Box&  box, const std::string& effect) const;
    /**
     * @brief Determines if a rule is applicable to the given element and effect.
     * @param element The element to be tested.
     * @param effect The effect to be tested.
     * @return True if the rule is applicable, false otherwise.
     */
    bool isRuleApplicable(const std::string& element, const std::string& effect) const;
    /**
     * @brief Get the destination box based on the direction.
     *
     * @param box Reference to the source box.
     * @param direction Direction in which the destination box is sought.
     * @return Box& Reference to the destination box.
     */
    Box& getDestinationBox(Box& box, Direction direction);
    /**
     * @brief Get the position of a given box on the game board.
     *
     * @param targetBox Reference to the box whose position is to be found.
     * @return Position The position of the target box.
     */
    Position getBoxPosition(const Box &targetBox) const;

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
     * @brief Find the position of a specified component on the game board.
     *
     * @param componentName The name of the component to find.
     * @return Position The position of the specified component.
     */
    Position findComponentPosition(const std::string& componentName);

    /**
     * @brief Clear pushable components from the game board.
     *
     * @param pushableComponents A vector of pushable components and their positions to be cleared from the board.
     */
    void clearPushableComponentsFromBoard(const std::vector<std::pair<Composant, Position> > &pushableComponents);

    /**
     * @brief Get the player's Composant object.
     *
     * @return Composant The player Composant.
     */
    Composant getPlayer();
    /**
     * @brief Get the positions of all player instances on the game board.
     *
     * @return std::vector<Position> A vector of positions for all player instances.
     */
    std::vector<Position> getPlayerPositions();
    /**
     * @brief Update positions of components with a specified direction.
     *
     * @param componentsPositions A vector of components and their positions to be updated.
     * @param dir The direction in which the positions are to be updated.
     */
    void updatePositionsInMapWithDirection(std::vector<std::pair<Composant, Position>>& componentsPositions, Direction& dir) ;
    /**
     * @brief Add components to the game board at specified positions.
     *
     * @param componentsPositions A vector of components and their positions to be added to the board.
     */
    void addComponentsToBoard(const std::vector<std::pair<Composant, Position>>& componentsPositions);
    /**
     * @brief Check if the last box is applicable, based on an effect and direction.
     *
     * @param startBox Reference to the starting box.
     * @param effect The effect to be checked.
     * @param dir The direction in which to check the effect.
     * @return bool True if the last box is applicable, otherwise false.
     */
    bool isLastBoxApplicable(Box& startBox, const std::string& effect, Direction& dir) ;

    /**
     * @brief Push the rule component boxes in a specified direction.
     *
     * @param startX The x-coordinate of the starting position.
     * @param startY The y-coordinate of the starting position.
     * @param dir The direction in which to push the rule component boxes.
     */
    void pushRuleComponentBoxes(int startX, int startY, Direction dir);
    /**
     * @brief Handles the side effects after pushing rule components on the game board.
     *
     * @param lastX The x-coordinate of the last box position.
     * @param lastY The y-coordinate of the last box position.
     * @param dir The current direction of the player.
     * @param board A 2D vector representing the game board.
     */
    void handleEffectsAfterPushingRuleComponents(int lastX, int lastY, Direction& dir, std::vector<std::vector<Box>>& board);
    /**
     * @brief Moves the player to a new position on the game board.
     *
     * @param pos The current position of the player.
     * @param destPos The destination position of the player.
     */
    void movePlayerToNewPosition(const Position& pos, const Position& destPos);
    /**
     * @brief Sinks the player into a new position on the game board.
     *
     * @param pos The current position of the player.
     * @param destPos The destination position of the player.
     */
    void sinkPlayer(const Position& pos, const Position& destPos);
    /**
     * @brief Moves the player to the position of the rule component on the game board.
     *
     * @param pos The current position of the player.
     * @param destPos The destination position of the player.
     * @param dir The current direction of the player.
     */
    void movePlayerToRuleComponentPosition(const Position& pos, const Position& destPos, Direction& dir);
    /**
     * @brief Pushes the rule components on the game board.
     *
     * @param pos The current position of the player.
     * @param destPos The destination position of the player.
     * @param dir The current direction of the player.
     * @param pushables A vector of pairs containing the rule components and their positions.
     */
    void pushRuleComponents(const Position& pos, const Position& destPos, Direction& dir, std::vector<std::pair<Composant, Position>>& pushables) ;
    /**
     * @brief Moves a non-rule component on the game board.
     *
     * @param pos The current position of the non-rule component.
     * @param destPos The destination position of the non-rule component.
     * @param dir The current direction of the player.
     */
    void moveNonRuleComponent(const Position& pos, const Position& destPos, Direction& dir);
    /**
     * @brief Applies effects and moves the player on the game board.
     *
     * @param pos The current position of the player.
     * @param destPos The destination position of the player.
     * @param lastBoxX The x-coordinate of the last box position.
     * @param lastBoxY The y-coordinate of the last box position.
     * @param dir The current direction of the player.
     * @param encountouredEmptyBox A boolean indicating if the player encountered an empty box.
     * @param ruleNotApplicableToLastBox A boolean indicating if the rule is not applicable to the last box.
     */
    void applyEffectsAndMove(const Position& pos, const Position& destPos, int lastBoxX, int lastBoxY, Direction& dir, bool encountouredEmptyBox, bool ruleNotApplicableToLastBox);
    /**
     * Handles the movement of a non-rule based game component.
     * @param pos The current position of the game component.
     * @param destPos The destination position of the game component.
     * @param dir The direction in which the game component is moving.
     */
    void handleNonRuleComponentName(const Position& pos, const Position& destPos, Direction& dir);
    /**
     * Handles the movement of a rule-based game component.
     * @param pos The current position of the game component.
     * @param destPos The destination position of the game component.
     * @param dir The direction in which the game component is moving.
     */
    void handleRuleComponentName(const Position& pos, const Position& destPos, Direction& dir);

    /**
     * Returns the current controller object.
     * @return The current controller object.
     */
    Controller getController(){
        return controller;
    }
    /**
     * Finds the position of the given Box object in the board.
     * @param targetBox The Box object for which the position is to be determined.
     * @return The position of the targetBox in the board as a Position object.
     * @throws std::runtime_error if the targetBox is not found in the board.
     */
    Position getPosition(/*const*/ Box& targetBox) const {
        for (size_t row = 0; row < m_board.size(); ++row) {
            for (size_t col = 0; col < m_board[row].size(); ++col) {
                if (m_board[row][col] == targetBox) {
                    return Position(static_cast<int>(row), static_cast<int>(col));
                }
            }
        }
        throw std::runtime_error("Box not found in the board.");
    }

    /**
     * Checks if the given string represents a valid integer within the range 0 to 18.
     * @param str The string to be checked.
     * @param msg The error message to be displayed if the integer is invalid.
     * @throws std::runtime_error if the integer is invalid or out of range.
     */
    void checkInteger(const std::string& str, const std::string& msg) {
        int nb = 0;
        try {
            nb = std::stoi(str);
        } catch (const std::invalid_argument& e) {
            throw std::runtime_error(msg);
        } catch (const std::out_of_range& e) {
            throw std::runtime_error(msg);
        }
        if(nb > 18){
            throw std::out_of_range("Enter value between 0 and 18\n\n");
        }
    }

    /**
     * Checks if the given string represents a valid direction ("UP", "RIGHT", "DOWN", or "LEFT").
     * @param str The string to be checked.
     * @param msg The error message to be displayed if the direction is invalid.
     * @throws std::invalid_argument if the direction is invalid.
     */
    void checkDirection(const std::string& str, const std::string& msg){
        if(!(str.compare("UP") || str.compare("RIGHT") || str.compare("DOWN") || str.compare("LEFT"))){
            throw std::invalid_argument(msg);
        }
    }
private:
    std::vector<Rule> rules;

    /**
     * @brief fileManager process all the file that are use to update the level
     */
    FileManager fileManager;
    /**
     * @brief player the current player
     */
    Composant player;
    int playerX;
    int playerY;

    std::vector<Position> playerPositions;
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
     * Extracts rules from the game board. Rules consist of a subject, a verb ("is"), and an effect.
     * Rules can be found horizontally or vertically on the board.
     * @return A vector of extracted rules.
     */
    std::vector<Rule> extractRules() {
        std::vector<Rule> extractedRules;

        std::unordered_set<std::string> validEffects{"push", "stop", "sink", "kill", "you", "win"};

        for (size_t i = 0; i < m_board.size(); ++i) {
            for (size_t j = 0; j < m_board[i].size() - 2; ++j) {
                auto& box1 = m_board[i][j];
                auto& box2 = m_board[i][j + 1];
                auto& box3 = m_board[i][j + 2];

                if (box1.isOccupied() && box2.isOccupied() && box3.isOccupied()) {
                    const std::string& elem1 = box1.getObjects().back().getName();
                    const std::string& elem2 = box2.getObjects().back().getName();
                    const std::string& elem3 = box3.getObjects().back().getName();

                    if (elem1.substr(0, 4) == "text" && elem2 == "is" && validEffects.count(elem3) > 0) {
                        rules.emplace_back(elem1.substr(5), elem2, elem3);
                    }
                }
            }
        }

        for (size_t j = 0; j < m_board[0].size(); ++j) {
            for (size_t i = 0; i < m_board.size() - 2; ++i) {
                auto& box1 = m_board[i][j];
                auto& box2 = m_board[i + 1][j];
                auto& box3 = m_board[i + 2][j];

                if (box1.isOccupied() && box2.isOccupied() && box3.isOccupied()) {
                    const std::string& elem1 = box1.getObjects().back().getName();
                    const std::string& elem2 = box2.getObjects().back().getName();
                    const std::string& elem3 = box3.getObjects().back().getName();

                    if (elem1.substr(0, 4) == "text" && elem2 == "is" && validEffects.count(elem3) > 0) {
                        rules.emplace_back(elem1.substr(5), elem2, elem3);
                    }
                }
            }
        }

        return rules;
    }

};


/**
 * Checks if the given string is in uppercase.
 * @param str The string to be checked.
 * @return true if the string is in uppercase, false otherwise.
 */
inline bool isUppercase(const std::string &str) {
    for (char c : str) {
        if (std::isalpha(c) && !std::isupper(c)) {
            return false;
        }
    }
    return true;
}

/**
 * Converts the given string to uppercase.
 * @param str The string to be converted.
 */
inline void turnToUpperCase(std::string &str){
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(str[i]);
    }
}
#endif // GAME_H
