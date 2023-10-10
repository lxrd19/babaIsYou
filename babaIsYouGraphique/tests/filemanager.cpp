#include "filemanager.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "direction.h"

int FileManager::getHeight() const{
    return height;
}

int FileManager::getWidth() const{
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

void FileManager::save(const std::vector<std::vector<Box>>& board){
    std::ofstream outFile("file/save.txt");
    if (!outFile) {
        std::cerr << "Unable to open file for saving.";
        return;
    }
    auto boardSizeLine = "18 18\n";
    outFile << boardSizeLine;
    for(size_t i = 0; i < board.size(); ++i){
        for(size_t j = 0; j < board[i].size(); ++j){
            auto& box = board[i][j];
            if(!box.isEmpty()){
                auto objects = box.getObjects();
                for(const auto& obj : objects){
                    auto name = obj.getName();
                    auto dir = obj.getDir();
                    auto dirStr = dir.toString();
                    std::string line = name.append(" " + std::to_string(j)).append(" " + std::to_string(i)).append(" " + dirStr).append("\n");
                    outFile<<line;
                }
            }
        }
    }
    savedLevel = currentLevel;
    outFile.close();
}


std::vector<std::vector<Box>> FileManager::load() {
    std::ifstream inFile("file/save.txt");
    if (!inFile) {
        std::cerr << "Unable to open file for loading.";
    }
    currentLevel = savedLevel;
    return readBoardFromFile("file/save.txt");
}


std::vector<std::vector<Box>> FileManager::readBoardFromFile(const std::string& path){
    std::vector<std::vector<Box>> board;
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

    return board;
}


void FileManager::nextLevel(){
    currentLevel = (currentLevel + 1) % MAX_LEVEL;
}

std::vector<std::vector<Box>> FileManager::changeLevel(){
    nextLevel();
    std::string fileName = "file/level_";
    std::string fileNameEnd = ".txt";
   return readBoardFromFile(fileName.append(std::to_string(currentLevel)).append(fileNameEnd));
}
