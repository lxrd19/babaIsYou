#include "movecommand.h"

MoveCommand::MoveCommand(const std::vector<std::string>& tokens, Game& game) :m_dir(Direction::generateDir(tokens[1])), m_game(game){}

void MoveCommand::execute(){
    m_game.move(m_dir);
}
