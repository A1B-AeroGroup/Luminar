#include <iostream>
#include <stdlib.h>
#include <vector>

#include "Object.hpp"
#include "Event.hpp"
#include "Scheduler.hpp"


class rocket : public object {
    public:
        std::vector<motor *> motors;
        rocket(int i):object(i) {
            std::cout << "Creating a rocket of mass: " << i << "..." << std::endl;
        }
};

class motor : public object {
    public:
        motor(double burntime, double thrust, double mass): object(mass) {
            motor::burntime = burntime;
            motor::thrust = thrust;
        }
    private:
        double burntime;
        doublek thrust;
};

class egg : public object {
    public:
        egg(int mass, double min_force) : object(mass) {
            egg::min_force = min_force;
        }
    private:
        double min_force;
};

int main() {
    motor m1(3, );
    return 0;
}