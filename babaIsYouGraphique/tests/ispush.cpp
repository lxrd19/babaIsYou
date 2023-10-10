#include "ispush.h"
#include "game.h"

IsPush::IsPush(Composant composant, Game& game) :
    m_composant(composant), m_game(game){}


void IsPush::apply(std::vector<std::vector<Box>>& board){
    m_game.getPushPosition() = findAll(board, m_composant);
}
