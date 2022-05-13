#include <iostream>
#include <stdlib.h>
#include <vector>

#include "Object.hpp"
#include "Event.hpp"
#include "Scheduler.hpp"
#include "Force.hpp"

/**
 * @brief Represents the rocket in this simulation.
 * Doesn't have any external variables.
 * 
 */
class rocket : public object {
    public:
        std::vector<motor *> motors;
        rocket(double mass):object(i) {
            std::cout << "Creating a rocket of mass: " << i << "..." << std::endl;
        }
};

/**
 * @brief Represents the motor in this simulation. The motor
 * will be added to the scheduler and callback functions will
 * be designed so that its effects are represented on the
 * rocket.
 * 
 */
class motor : public object {
    public:
        motor(double burntime, double thrust, double mass): object(mass) {
            motor::burntime = burntime;
            motor::thrust = thrust;
        }

        double getBurnTime() {
            return burntime;
        }
    private:
        double burntime;
        double thrust;
};

/**
 * @brief The egg is represented as an abstraction of
 * the object class and has a minimum force attribute.
 * 
 */
class egg : public object {
    public:
        egg(int mass, double min_force) : object(mass) {
            egg::min_force = min_force;
        }
    private:
        double min_force;
};

/* methods */
void toggle_motor(void) {
    static bool motorOn = false; // should persist
    if (!motorOn) {

    }
}

int main() {
    /* global sim forces */
    force gravity(0, -9.8, 0);

    /* sim objects */
    motor aerotechg80t(3, 136.6, 0.1279);
    rocket r(1.4);
    egg e(0.0496, 24.5);

    scheduler sch("logfile.txt");
    
    /* set the events */
    // sets the global gravity
    

    /* rus the scheduler */
    sch.run();

    /* performs all necessary destructions */

    return 0;
}