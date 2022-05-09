#include "Force.hpp"
#include <math.h>

/* PUBLIC */
force::force(double x, double y, double z) {
    setForce(plane::x, x);
    setForce(plane::y, y);
    setForce(plane::z, z);
};

double force::setForce(plane p, double f) {
    double last;
    switch(p) {
        case plane::x:
            last = x;
            x = f;
            break;
        case plane::y:
            last = x;
            y = f;
            break;
        case plane::z:
            last = x;
            z = f;
            break;
        default:
            break;
    }
    return last;
}

void force::incrementForce(plane p, double f) {
    switch(p) {
        case plane::x:
            force::x += f;
            break;
        case plane::y:
            force::y += f;
            break;
        case plane::z:
            force::z += f;
            break;
        default:
            break;
    }
}

void force::getMagnitude(double **m) {
    // do the calculations
    double sum_sqr = (x*x) + (y*y) + (z*z);
    **m = std::sqrt(sum_sqr);
}

double force::getForce(plane p) {
    switch(p) {
        case plane::x:
            return x;
            break;
        case plane::y:
            return y;
            break;
        case plane::z:
            return z;
            break;
        default:
            break;
    }
};
