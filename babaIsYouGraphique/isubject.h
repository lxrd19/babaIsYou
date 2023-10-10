#ifndef ISUBJECT_H
#define ISUBJECT_H
/**
 *@brief IObserver Abstract class of all observer, should be use later in the code
 */
class IObserver;

/**
 * @brief The ISubject class base class of all subject
 */
class ISubject{
public:
    /**
     * @brief attach add one more observer to the list of observers
     */
    virtual void attach(IObserver*) =0;
    /**
     * @brief detach remove the given observer of the list
     */
    virtual void detach(IObserver *) =0;
    /**
     * @brief notify this method is implemented by all observers to warn the view of an update
     */
    virtual void notify() =0;
    /**
     * @brief ~ISubject virtual destructor of the subject
     */
    virtual ~ISubject();
};

#endif // ISUBJECT_H
