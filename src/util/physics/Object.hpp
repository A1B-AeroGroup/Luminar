#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>
#include <vector>
#include "Force.hpp"

class object {
    public:
        object();
        object(double mass);
        
        std::vector<force> forces;
        
    private:
        /* scalar attributes */
        double mass;
        
        /* vector attributes */
        double x, y, z;
        double vx, vy, vz;
        double ax, ay, az;
};

#endif