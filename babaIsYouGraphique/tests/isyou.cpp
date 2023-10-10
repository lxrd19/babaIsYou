#include "isyou.h"
#include "game.h"

IsYou::IsYou(Composant composant, Game& game) : m_composant(composant),
    m_game(game){}

void IsYou::apply(std::vector<std::vector<Box>>& board){
    m_game.getYouPosition() = findAll(board, m_composant);
}

