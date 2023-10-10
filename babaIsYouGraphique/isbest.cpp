#include "isbest.h"
#include "game.h"

IsBest::IsBest(Composant composant, Game& game) :
    m_composant(composant),
    m_game(game){}



void IsBest::apply(std::vector<std::vector<Box>>& board){
    m_game.getBestPosition() = findAll(board, m_composant);
}
