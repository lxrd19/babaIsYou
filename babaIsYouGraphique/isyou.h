#ifndef ISYOU_H
#define ISYOU_H
#include "box.h"
#include "irule.h"
#include <algorithm>
class Game;

/**
 * Class representing the "is you" rule.
 */
class IsYou : public Irule{
public:
    /**
     * Constructs an IsYou rule with the given component and game.
     *
     * @param composant The component of the rule.
     * @param game The game object.
     */
    IsYou(Composant composant, Game& game);
    /**
     * Applies the "is you" rule to the game board.
     *
     * @param board The game board to apply the rule to.
     */
    void apply(std::vector<std::vector<Box>>& board) override;

private:
    Composant m_composant;
    Game& m_game;
};

#endif // ISYOU_H
