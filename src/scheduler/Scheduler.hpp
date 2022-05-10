#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdlib.h>
#include <vector>

#include "Queue.hpp"
#include "Event.hpp"

class scheduler {
    public:
        std::vector<event> q_events;
        /* constructors */
        scheduler();

        /* methods */
        void addTriggeredEvent(
            int time_step, void (*callback)(void)
        );

        void addTriggeredEvent(
            double simulation_time, void (*callback)(void)
        );
    private:
};

#endif