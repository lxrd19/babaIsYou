#ifndef ISKILL_H
#define ISKILL_H
#include "irule.h"

class Game;
/**
 * Class representing the "is kill" rule.
 */
class IsKill : public Irule{
public:
    /**
     * Constructs an IsKill rule with the given component and game.
     *
     * @param composant The component of the rule.
     * @param game The game object.
     */
    IsKill(Composant composant, Game& game);
    /**
     * Applies the "is kill" rule to the game board.
     *
     * @param board The game board to apply the rule to.
     */
    void apply(std::vector<std::vector<Box>>& board) override;

private:
    Composant  m_composant;
    Game& m_game;
};

#endif // ISKILL_H
