#ifndef POSITION_H
#define POSITION_H

/**
 * @brief The Position class Position of an item on the board
 */
class Position{
public:
    /**
     * @brief Position constructor of a Position
     */
    Position(int, int);
    /**
     * @brief getX return the abscissa
     * @return the abscisse
     */
    const int getX() const;
    /**
     * @brief getY return the ordinate
     * @return the ordinate
     */
    const int getY() const;
    /**
     * @brief operator = checks if the current positions equals to the one given in parameter
     * @return true if the actual position is the same as the one given in parameter
     */
    bool operator=(const Position&);
private:
    /**
     * @brief x the abscissa
     */
    int x;
    /**
     * @brief y the ordinate
     */
    int y;

};

#endif // POSITION_H
