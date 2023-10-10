#ifndef IOBSERVER_H
#define IOBSERVER_H

/**
 *@brief ISubject Abstract class of all subject, should be use later in the code
 */
class ISubject;

class IObserver{
    /**
     * @brief ~IObserver virtual destructor of observer for polymorphic use
     */
    virtual ~IObserver()=0;
    /**
     * @brief update This must be implemented by  all  the observer,  this method is called when the subject want to notify
     * observers
     * @param game the model
     */
    virtual void update(const ISubject& game) =0;
};

#endif // IOBSERVER_H
