#include <iostream>
#include "filemanager.h"
#include "boardview.h"
#include "game.h"
#include <stdexcept>
#include <exception>
using namespace std;


int main(){
    auto f = FileManager();
    std::vector<std::vector<Box>> vec{};
    std::string path = "file/level_0.txt";
    f.initBoard(path, vec);
    auto game = Game(vec);
    auto view = BoardView(game.getController());
    game.attach(&view);
    view.print(vec);

    std::string input;
    while (true) {
        if(!(game.getPlayerX() < 0 && game.getPlayerY() < 0)){
            std::cout << "Player position-->" << " Row:" << game.getPlayerX() + 1 << " Column:" << game.getPlayerY() + 1 << std::endl;
        }else{
            std::cout << "Player is all " << game.getPlayer().getName() << " on the board" << std::endl;
            std::cout << "Enter command like \"move LEFT\" to move them" << std::endl;
        }
        std::cout << "Enter command: ";
        std::getline(std::cin, input);

        if (input == "quit" || input == "exit") {
            break;
        }
        try {
            game.handleUserInput(input);
        } catch (const std::exception& ex) {
            std::cout << ex.what();
        }
    }

    return 0;
}





