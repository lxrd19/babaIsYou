#include "movecommandnoposition.h"

MoveCommandNoPosition::MoveCommandNoPosition(const std::vector<std::string> & tokens, Game& game):
    m_dir(Direction::generateDir(tokens[1])), m_game(game){}


void MoveCommandNoPosition::execute(){
    m_game.updateCurrentPlayer();
    auto playerPositions = m_game.getPlayerPositions();

    if(!playerPositions.empty()){
        for(size_t i = 0; i < playerPositions.size(); ++i){
            if(i == playerPositions.size()){
                break;
            }
            m_game.move(playerPositions[i], m_dir);
        }
        return;
    }
}
