#ifndef ISBEST_H
#define ISBEST_H
#include "irule.h"
class Game;
/**
 * Class representing the "is best" rule.
 */
class IsBest : public Irule{
public:
    /**
     * Constructs an IsBest rule with the given component and game.
     *
     * @param composant The component of the rule.
     * @param game The game object.
     */
    IsBest(Composant composant, Game& game);
    /**
     * Applies the "is best" rule to the game board.
     *
     * @param board The game board to apply the rule to.
     */
    void apply(std::vector<std::vector<Box>>& board) override;
private:
    Composant  m_composant;
    Game& m_game;
};
#endif // ISBEST_H
