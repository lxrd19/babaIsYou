#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H
#include "direction.h"
#include "game.h"
#include "command.h"
/**
 * @brief The MoveCommand class
 */
class MoveCommand : public ICommand
{
public:
    /**
     * @brief MoveCommand Constructs a MoveCommand object with the tokens the direction and the model
     * @param tokens the name
     * @param dir the direction
     * @param game the model
     */
    MoveCommand(const std::vector<std::string>& tokens, Game& game);
    void execute() override;
private :
    Direction m_dir;
    Game& m_game;
};

#endif // MOVECOMMAND_H
