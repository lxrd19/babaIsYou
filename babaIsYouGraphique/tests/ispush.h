#ifndef ISPUSH_H
#define ISPUSH_H

#include "irule.h"

class Game;
/**
 * Class representing the "is push" rule.
 */
class IsPush : public Irule{
public:
    /**
     * Constructs an IsPush rule with the given component and game.
     *
     * @param composant The component of the rule.
     * @param game The game object.
     */
    IsPush(Composant composant, Game& game);
    /**
     * Applies the "is push" rule to the game board.
     *
     * @param board The game board to apply the rule to.
     */
    void apply(std::vector<std::vector<Box>>& board) override;

private:
    Composant m_composant;
    Game& m_game;
};

#endif // ISPUSH_H
