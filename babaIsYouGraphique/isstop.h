#ifndef ISSTOP_H
#define ISSTOP_H

#include "irule.h"
class Game;
/**
 * Class representing the "is stop" rule.
 */
class IsStop : public Irule{
public:
    /**
     * Constructs an IsStop rule with the given component and game.
     *
     * @param composant The component of the rule.
     * @param game The game object.
     */
    IsStop(Composant composant, Game &game);
    /**
     * Applies the "is stop" rule to the game board.
     *
     * @param board The game board to apply the rule to.
     */
    void apply(std::vector<std::vector<Box>>& board) override;

private:
    Composant m_composant;
    Game& m_game;
};

#endif // ISSTOP_H
