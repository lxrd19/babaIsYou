#include "iskill.h"
#include "game.h"

IsKill::IsKill(Composant composant, Game& game) :
    m_composant(composant),  m_game(game){}


void IsKill::apply(std::vector<std::vector<Box>>& board){
    m_game.getKillPosition() = findAll(board, m_composant);
}

