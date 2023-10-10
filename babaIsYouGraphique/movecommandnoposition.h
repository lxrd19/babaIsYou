#ifndef MOVECOMMANDNOPOSITION_H
#define MOVECOMMANDNOPOSITION_H
#include "direction.h"
#include "game.h"
#include "command.h"
/**
 * @brief The MoveCommandNoPosition class
 */
class MoveCommandNoPosition : public ICommand
{
public:
    /**
     * @brief MoveCommandNoPosition Constructs a MoveCommandNoPosition object with the tokens and the model
     * @param tokens the name
     * @param game the model
     */
//    MoveCommandNoPosition(const std::vector<std::string> & tokens, Game& game);
    void execute() override;
private :

    std::vector<std::vector<Box>> m_board;
    Direction m_dir;
    Game& m_game;
};

#endif // MOVECOMMANDNOPOSITION_H
