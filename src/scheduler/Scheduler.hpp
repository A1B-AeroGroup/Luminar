#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdlib.h>
#include <vector>

#include "Queue.hpp"
#include "Event.hpp"
#include "Force.hpp"

class scheduler {
    public:
        std::vector<event> q_events;

        /* constructors */
        scheduler();
        scheduler(char *logFilePath);

        /* methods */
        void setEventTickTime(
            int time_step, void (*callback)(void)
        );

        void setEventSimulationTime(
            double simulation_time, void (*callback)(void)
        );
        
        void run();
    private:
};

#endif