#ifndef IOBSERVER_H
#define IOBSERVER_H
#include "command.h"
#include <memory>
#include <iostream>
/**
 *@brief ISubject Abstract class of all subject, should be use later in the code
 */
class ISubject;

class IObserver{
public:
    virtual ~IObserver();
    virtual void update(const ISubject* game) = 0;
    virtual void onCommand(std::shared_ptr<ICommand> command) = 0;
};

#endif // IOBSERVER_H
