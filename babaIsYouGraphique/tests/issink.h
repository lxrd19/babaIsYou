#ifndef ISSINK_H
#define ISSINK_H
#include "irule.h"
class Game;
/**
 * Class representing the "is sink" rule.
 */
class IsSink : public Irule{
public:
    /**
     * Constructs an IsSink rule with the given component and game.
     *
     * @param composant The component of the rule.
     * @param game The game object.
     */
    IsSink(Composant composant, Game& game);
    /**
     * Applies the "is sink" rule to the game board.
     *
     * @param board The game board to apply the rule to.
     */
    void apply(std::vector<std::vector<Box>>& board) override;


private:
    Composant m_composant;
    Game& m_game;
};

#endif // ISSINK_H
