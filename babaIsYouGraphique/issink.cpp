#include "issink.h"
#include "game.h"

IsSink::IsSink(Composant composant, Game& game) :
    m_composant(composant),
    m_game(game){}


void IsSink::apply(std::vector<std::vector<Box>>& board){

    m_game.getSinkPosition() = findAll(board, m_composant);
}

