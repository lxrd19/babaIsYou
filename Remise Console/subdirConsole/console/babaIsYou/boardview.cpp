#include "boardview.h"
#include "game.h"
#include <iostream>
#include <sstream>
#include <iomanip>

IObserver::~IObserver(){}
BoardView::~BoardView(){}

BoardView::BoardView(const Controller& control):controller(control)
{}

BoardView::BoardView(){
    Controller c;
    controller = c;
}

void BoardView::update(const ISubject* game){
    auto myGame = dynamic_cast<const Game*>(game);
    BoardView::print(myGame->getBoard());
}

void BoardView::onCommand(std::shared_ptr<ICommand> command) {
    if(command){
        command->execute();
    }
}



void BoardView::print(const std::vector<std::vector<Box>>& board /*int width*/){
    int row = 0;
    showFirstLine(board, board.size());

    for(size_t i = 0; i < board.size(); ++i){
        std::cout << std::endl;
        row < 9 ? std::cout << row + 1 << " |" : std::cout << row + 1 << "|";
        for(size_t j = 0; j < board[i].size(); ++j){
            const auto& box = board.at(i).at(j);
            const auto& objects = box.getObjects();

            if(objects.empty()){
                std::cout << std::setw(3) << " ";
            }else{
                const auto name = objects.back().getName();
                std::cout << std::setw(3) << getSymbol(name);
            }
        }
        ++row;
    }
    std::cout << std::endl;
}





