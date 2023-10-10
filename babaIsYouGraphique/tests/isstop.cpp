#include "isstop.h"
#include "game.h"


IsStop::IsStop(Composant composant, Game& game) :
    m_composant(composant), m_game(game){}


void IsStop::apply(std::vector<std::vector<Box>>& board){
    m_game.getStopPosition() = findAll(board, m_composant);
}



