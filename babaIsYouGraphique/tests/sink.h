#ifndef SINK_H
#define SINK_H


#include "effect.h"
/**
 * @brief The Sink class
 */
class Sink : public Effect
{
public:
    /**
     * @brief Sink Constructs a sink object with the name and the direction
     * @param name the name
     * @param dir the direction
     */
    Sink(const std::string& name, const Direction& dir);
private:
    std::string  m_name;
    Direction m_dir = Direction::RIGHT;
};

#endif // SINK_H
