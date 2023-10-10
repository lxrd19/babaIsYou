#ifndef ISWIN_H
#define ISWIN_H


#include "irule.h"

class Game;
/**
 * Class representing the "is win" rule.
 */
class IsWin : public Irule{
public:
    /**
     * Constructs an IsWin rule with the given component and game.
     *
     * @param composant The component of the rule.
     * @param game The game object.
     */
    IsWin(Composant composant, Game& game);
    /**
     * Applies the "is win" rule to the game board.
     *
     * @param board The game board to apply the rule to.
     */
    void apply(std::vector<std::vector<Box>>& board) override;

private:
    Composant m_composant;
    Game& m_game;
};

#endif // ISWIN_H
