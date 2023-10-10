#ifndef MANAGEDATA_H
#define MANAGEDATA_H
#include <map>
#include "box.h"
#include "command.h"
#include "irule.h"

class Game;
class MoveCommand;
/**
 * Manages data related to the game.
 */
class ManageData{

private:
    Game& m_game;
public:
    /**
     * Handles user input and returns the corresponding command.
     *
     * @param input The user input.
     * @return The command based on the user input.
    */
    std::shared_ptr<ICommand> handleUserInputUpdated(const std::string& input);
    /**
        * Checks if a given name is a rule component name.
        *
        * @param name The name to check.
        * @return True if the name is a rule component name, false otherwise.
    */
    bool isRuleComponantName(const std::string& name);
    /**
     * Constructs a ManageData object for the given game.
     *
     * @param game The game object to manage data for.
     */
    ManageData(Game &game);
    /**
     * Gets the positions of "is" components on the game board.
     *
     * @param board The game board.
     * @return The positions of "is" components.
     */
    std::vector<Position> getIsPositions(const std::vector<std::vector<Box>>& board);

    /**
     * Finds vertical rules on the game board and adds them to the provided rules vector.
     *
     * @param board The game board.
     * @param rules The vector to store the found rules.
     */
    void findVerticalRules(const std::vector<std::vector<Box>>& board,
                           std::vector<std::unique_ptr<Irule>>& rules);
    /**
     * Finds horizontal rules on the game board and adds them to the provided rules vector.
     *
     * @param board The game board.
     * @param rules The vector to store the found rules.
     */
    void findHorizontalRules(const std::vector<std::vector<Box>>& board,
                             std::vector<std::unique_ptr<Irule>>& rules);

};


   /**
     * Checks if the given string represents a valid integer within the range 0 to 18.
     * @param str The string to be checked.
     * @param msg The error message to be displayed if the integer is invalid.
     * @throws std::runtime_error if the integer is invalid or out of range.
   */
inline void checkInteger(const std::string& str, const std::string& msg) {
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
inline void checkDirection(const std::string& str, const std::string& msg){
    if(!(str.compare("UP") || str.compare("RIGHT") || str.compare("DOWN") || str.compare("LEFT"))){
        throw std::invalid_argument(msg);
    }
}
/**
 * Generates the element name from a given text.
 *
 * @param text The input text.
 * @return The generated element name, or an empty string if not found.
 */
inline const std::string generateElementName(const std::string text){
    std::string res;
    static const std::map<std::string, std::string> nameMap {
        {"text_baba", "baba"},
        {"text_grass", "grass"},
        {"text_rock", "rock"},
        {"text_wall", "wall"},
        {"text_flag", "flag"},
        {"text_water", "water"},
        {"text_lava", "lava"}
    };

    auto it = nameMap.find(text);
    if (it != nameMap.end()) {
        res = it->second;
    }
    return res;
}
/**
 * Checks if a position is inside the board.
 *
 * @param board The game board.
 * @param pos The position to check.
 * @return True if the position is inside the board, false otherwise.
 */
inline bool isInside(const std::vector<std::vector<Box>>& board , const Position& pos) {
    size_t x = pos.getX();
    size_t y = pos.getY();
    return x < board.size() && y < board[0].size();
}

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
#endif // MANAGEDATA_H
