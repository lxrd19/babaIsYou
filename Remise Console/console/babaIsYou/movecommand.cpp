#include "movecommand.h"

MoveCommand::MoveCommand(const std::vector<std::string>& tokens, const Direction& dir, Game& game) : m_x(std::stoi(tokens[1])), m_y(std::stoi(tokens[2])), m_dir(Direction::generateDir(tokens[3])), m_game(game){}

void MoveCommand::execute(){

    m_game.move(Position(m_x-1, m_y-1), m_dir);
}
