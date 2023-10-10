#ifndef OBJECTSTATE_H
#define OBJECTSTATE_H

/**
 * @brief The ObjectState class this class represent all the state of each material on the board
 */
class ObjectState{

public:
    /**
     * @brief ObjectState constructor of a state
     * @param pushable checks if the object is pushable
     * @param traversable checks if the object is traversable
     */
    ObjectState(bool pushable, bool traversable);
    /**
     * @brief setPushable update the pushable state
     * @param state the new state
    */
    void setPushable(bool state);
    /**
     * @brief setTraversable update the traversable state
     * @param state the new state
    */
    void setTraversable(bool state);


    /**
     * @brief getPushable return the pushable state
     * @return true if the material is pushable
     */
    bool getPushable()const;

    /**
     * @brief getTraversable return the traversable state
     * @return true if the material is traversable
     */
    bool getTraversable()const;
private:
    /**
     * @brief isPushable checks if the material is pushable, false by default
     */
    bool isPushable = false;
    /**
     * @brief isTraversable checks if the material is traversable, true by default
     */

    bool isTraversable = true;

};
#endif // OBJECTSTATE_H
