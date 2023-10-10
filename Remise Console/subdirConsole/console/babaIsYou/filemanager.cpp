#include "filemanager.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "direction.h"

const int FileManager::getHeight() const{
    return height;
}

const int FileManager::getWidth() const{
    return width;
}

void FileManager::initBoard(const std::string& path, std::vector<std::vector<Box>>& board){
    std::ifstream ifs(path, std::ios::in);
    std::string line;
    std::string objectName;
    int x;
    int y;
    std::string objectDirection = "";

    if(ifs){
        bool isFirstLine = true;
        while(std::getline(ifs, line)){
            std::istringstream ist(line);
            if(isFirstLine){
                ist >> this->height >> this->width;
                isFirstLine = false;
                initBoardValue(board, height, width);
                continue;
            }
            ist >> objectName >> y >> x >> objectDirection;
            auto dir = getDir(objectDirection);
            board[x][y].addObject(create(objectName,  dir));

        }
    }else{
        std::cerr << "cannot open file !" << std::endl;
    }

}

void FileManager::nextLevel(){
    currentLevel = (currentLevel + 1) % MAX_LEVEL;
}

void FileManager::changeLevel(std::vector<std::vector<Box>>& board){
    nextLevel();
    std::string fileName = "file/level_";
    std::string fileNameEnd = ".txt";
    if(!board.empty()){
        board.clear();
    }
    initBoard(fileName.append(std::to_string(currentLevel)).append(fileNameEnd), board);

}
