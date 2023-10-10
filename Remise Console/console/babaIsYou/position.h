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
    Position() = default;
    Position(int, int);

    Position(const Position&) = default;
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
        * Compares two Position objects for equality.
        * @param other The other Position object to compare with.
        * @return True if the Position objects are equal, false otherwise.
    */
    bool  operator==(const Position&) const;
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
