#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <strstream>
#include <vector>
#include <memory>
#include "Box.h"

/**
 * @brief The FileManager class Represent all the features of a file
 */
class FileManager{
public:
    /**
     * @brief FileManager creates filemanager that will fill the board
     */
    FileManager();

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
    void initBoard(const std::string& path, std::vector<std::vector<Box*>>& board);

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
    void changeLevel(std::vector<std::vector<Box*>>& board);

    /**
     * @brief setLevel update the vector with current level
     * @param index the index of the file to use
     */
    void setLevel(int index);
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
    int currentLevel;
};

#endif // FILEMANAGER_H
