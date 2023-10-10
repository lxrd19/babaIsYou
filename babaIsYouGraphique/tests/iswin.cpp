#include "iswin.h"
#include "game.h"


IsWin::IsWin(Composant composant, Game& game) :
    m_composant(composant),
    m_game(game){}


void IsWin::apply(std::vector<std::vector<Box>>& board){
    m_game.getWinPosition() = findAll(board, m_composant);
}
