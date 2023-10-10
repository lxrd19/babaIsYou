#ifndef COMMAND_H
#define COMMAND_H
/**
 * @brief The ICommand class
 */
class ICommand{
public:
    /**
     * @brief ~ICommand Constructs Icommand object for the pattern Command
     */
    virtual ~ICommand(){};
    /**
     * @brief execute Executes the command
     */
    virtual void execute() = 0;
};

#endif // COMMAND_H
