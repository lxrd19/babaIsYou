#ifndef MANAGEDATA_H
#define MANAGEDATA_H
#include <map>
#include "box.h"
#include "command.h"
#include "irule.h"

class Game;
class MoveCommand;

class ManageData{

private:
    Game& m_game;
public:
    std::shared_ptr<ICommand> handleUserInputUpdated(const std::string& input);
    bool isRuleComponantName(const std::string& name);
    //    ManageData() = default;
    ManageData(Game &game);
    std::vector<Position> getIsPositions(const std::vector<std::vector<Box>>& board);

    void findVerticalRules(const std::vector<std::vector<Box>>& board,
                           std::vector<std::unique_ptr<Irule>>& rules);
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
