#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <vector>
#include <memory>
#include "box.h"
#include "baba.h"
#include "metal.h"
#include "textobject.h"
#include "rock.h"
#include "lava.h"
#include "flag.h"
#include "wall.h"
#include "goop.h"
#include "grass.h"

#define MAX_LEVEL 5


/**
 * @brief The FileManager class Represent all the features of a file
 */
class FileManager{
public:
    /**
     * @brief FileManager creates filemanager that will fill the board
     */
    FileManager() = default;

    /**
     * @brief save Saves the actual level of the game in the given file stream
     * @param path the file name where to save the level
     */
    void save(std::string& path);
    /**
     * @brief load Loads the level of the game given by the stream, this will
     * fill the board with the content of the file
     * @param path the file name use to fill the board
     */
    void load(const std::string& path);
    /**
     * @brief initBoard Fill the given vector with the path
     *
     * @param path the path of the file that is use to fill the vector
     * @param board the board to fill with the given file
     */
    void initBoard(const std::string& path, std::vector<std::vector<Box>>& board);

    /**
     * @brief getHeight return the height of the board
     * @return height of the board
     */
    const int getHeight() const;
    /**
     * @brief getWidth return the width of the board
     * @return width of the board
     */
    const int getWidth() const;

    /**
     * @brief getLevel returns all levels of the game
     * @return the levels
     */
    const int& getLevel() const;
    /**
     * @brief changeLevel update the vector with current level
     * @param board the vector to update
     */
    void changeLevel(std::vector<std::vector<Box>>& board);

    /**
     * @brief setLevel update the vector with current level
     * @param index the index of the file to use
     */
    void nextLevel()/*const*/;

private:
    /**
     * @brief height Height of the board, is given in the first line of the file
     */
    int height;
    /**
     * @brief width width of the board, is given in the first line of the file
     */
    int width;
    /**
     * @brief currentLevel top 5 levels of the game
     */
    int currentLevel = 0;

};



/**
 * @brief initBoardValue initializes the board boxes.
 * @param boxes the board
 * @param outterSize the innersize
 * @param innerSize the outtersize
 */
inline void initBoardValue(std::vector<std::vector<Box>>& boxes, const int& outterSize, const int& innerSize){
   boxes.resize(outterSize);
    for(auto& el : boxes){
        el.resize(innerSize);
    }
    for (int i = 0; i < outterSize; ++i) {
        for (int j = 0; j < innerSize; ++j) {
            boxes[i][j] = Box();
        }
    }
}

/**
 * @brief getDir Gives the direction from the given input
 * @param text the string representing the direction
 * @return the direction
 */
inline Direction getDir(std::string text){
    if(!text.compare("0")){
        return Direction::RIGHT;
    }else if(!text.compare("1")){
        return Direction::UP;
    }else if(!text.compare("2")){
        return Direction::LEFT;
    }else{
        return Direction::DOWN;
    }
}

/**
 * @brief create Creates an object according to the given text which is the name and the direction
 * @param text the name
 * @param dir the direction
 * @return the object
 */
inline Composant create(const std::string& text, const Direction& dir){
    Composant result;
    if(!text.compare("text_rock")){
        result = TextObject(text, dir);
    }else if(!text.compare("text_wall")){
        result = TextObject(text, dir);
    }else if(!text.compare("text_flag")){
        result = TextObject(text, dir);
    }else if(!text.compare("win")){
        result = TextObject(text, dir);
    }else if(!text.compare("is")){
        result = TextObject(text, dir);
    }else if(!text.compare("text_baba")){
        result = TextObject(text, dir);
    }else if(!text.compare("text_grass")){
        result = TextObject(text, dir);
    }else if(!text.compare("text_water")){
        result = TextObject(text, dir);
    }else if(!text.compare("text_rock")){
        result = TextObject(text, dir);
    }else if(!text.compare("text_lava")){
        result = TextObject(text, dir);
    }else if(!text.compare("push")){
        result = TextObject(text, dir);
    }else if(!text.compare("you")){
        result = TextObject(text, dir);
    }else if(!text.compare("best")){
        result = TextObject(text, dir);
    }else if(!text.compare("kill")){
        result = TextObject(text, dir);
    }else if(!text.compare("sink")){
        result = TextObject(text, dir);
    }else if(!text.compare("stop")){
        result = TextObject(text, dir);
    }else if(!text.compare("flag")){
        result = Flag(text, dir);
    }else if(!text.compare("metal")){
        result = Metal(text, dir);
    }else if(!text.compare("baba")){
        result = Baba(text, dir);
    }else if(!text.compare("rock")){
        result = Rock(text, dir);
    }else if(!text.compare("lava")){
        result = Lava(text, dir);
    }else if(!text.compare("wall")){
        result = Wall(text, dir);
    }else if(!text.compare("water")){
        result = Goop(text, dir);
    }else if(!text.compare("grass")){
        result = Grass(text, dir);
    }

    return result;
}


#endif // FILEMANAGER_H
