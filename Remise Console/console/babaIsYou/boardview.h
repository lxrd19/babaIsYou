#ifndef BOARDVIEW_H
#define BOARDVIEW_H
#include "controller.h"
#include "iobserver.h"
#include <vector>
#include "box.h"
#include "command.h"
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


    BoardView();
    /**
     * @brief update
     * this method is called by all subject when change
     * happened in the game
     * @param game the subject
     */
    void update(const ISubject* game) override;

    //    /**
    //     * @brief print print the board
    //     * @param board the board
    //     */

    void print(const std::vector<std::vector<Box>>& board);

    /**
     * @brief isInside checks if an item is on the board
     * @param pos the position to check
     * @return true if the object is on the board
     */
    bool isInside(const Position& pos) const;

    /**
        * Handles the given command by executing it.
        * This function overrides the onCommand function declared in MyBaseClass.
        * @param command A shared pointer to an ICommand object.
    */

    void onCommand(std::shared_ptr<ICommand> command) override;
    /**
     * @brief controller verify  the validity of user input
     */
    Controller controller;
};
/**
 * Returns the symbol corresponding to the given text.
 * @param text The text representing a game object.
 * @return The symbol corresponding to the given text as a string.
 */
inline std::string getSymbol(const std::string& text){
    std::string result;
    if(!text.compare("text_rock")){
        result = "TR";
    }else if(!text.compare("text_wall")){
        result = "T#";
    }else if(!text.compare("text_flag")){
        result = "TF";
    }else if(!text.compare("win")){
        result = "WI";
    }else if(!text.compare("is")){
        result = "IS";
    }else if(!text.compare("text_baba")){
        result = "TB";
    }else if(!text.compare("text_grass")){
        result = "T*";
    }else if(!text.compare("text_water")){
        result = "T$";
    }else if(!text.compare("text_lava")){
        result = "T%";
    }else if(!text.compare("push")){
        result = "PU";
    }else if(!text.compare("best")){
        result = "TV";
    }else if(!text.compare("kill")){
        result = "KI";
    }else if(!text.compare("sink")){
        result = "SI";
    }else if(!text.compare("stop")){
        result = "ST";
    }else if(!text.compare("flag")){
        result = "FL";
    }else if(!text.compare("metal")){
        result = "ME";
    }else if(!text.compare("baba")){
        result = "BA";
    }else if(!text.compare("rock")){
        result = "RO";
    }else if(!text.compare("lava")){
        result = "LA";
    }else if(!text.compare("wall")){
        result = "WA";
    }else if(!text.compare("water")){
        result = "$$";
    }else if(!text.compare("grass")){
        result = "**";
    }else if(!text.compare("you")){
        result = "YO";
    }
    return result;
}
/**
 * Displays the first line of the game board, which contains column numbers.
 * @param board The game board represented as a 2D vector of Box objects.
 * @param width The width of the game board.
 */
inline void showFirstLine(const std::vector<std::vector<Box>>& board, int width){
    std::string len{};

    for (int n = 0; n < width ; ++n){
        len.append(n+1 >= 10 ? std::to_string(n+1)+ "  " : std::to_string(n+1)+ " ");
    }
    int column = 1;
    std::cout << "    ";
    for(auto t = board[0].begin(); t != board[0].end(); ++t){
        column >= 10  ? std::cout << column << " " : std::cout << column << "  ";
        ++column;
    }
    std::cout<< std::endl;
    std::cout << "   ";

    for(size_t k = 0; k < len.size(); ++k){
        std::cout << "=";
    }
}

#endif // BOARDVIEW_H
