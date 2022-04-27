/* system level imports */
#include <iostream>

/* user level imports */
#include "example_sim_1.hpp"

/* rocket variables (using standard units) */
// rocket acceleration
double a_rx = 0;
double a_ry = -9.8;
double mass = 2.1;

// rocket velocity
double v_rx = 0;
double v_ry = 0;

// rocket displacement
double s_rx = 0;
double s_ry = 0;

/* egg variables */
// egg acceleration
double a_ex = 0;
double a_ey = -9.8;
double mass_e = 0.0568;

// egg velocity
double v_ex = 0;
double v_ey = 0;

// egg displacement
double s_ex = 0;
double s_ey = 0;

/* motor variables (G38FJ) */
double impulse = 87.7; // Ns
double burn = 2.2; // s

/* simulation variables */
unsigned int time_step = 0;
unsigned int time_delta = 1;
unsigned int total_time = 0;
bool egg_broke = false;


int step() {
    /* store some vars */
    double lv_ry = v_ry; // last velocity in the y for the rocket

    /* update forces acting on rocket */
    if (total_time < burn) {
        v_ry += (impulse/mass);
    }

    /* update velocity */
    v_rx += a_rx;
    v_ry += ((a_ry) * (double) time_delta);

    s_rx += v_rx;
    s_ry += v_ry;

    /* calculate the force  */
    double force_on_egg = mass_e * (v_ry - lv_ry);
    if (force_on_egg > 24.5) {
        egg_broke = true;
    }

    total_time += time_delta;
    time_step++;
    return 0;
}

int main() {
    std::cout << "Starting Egg Rocket Simulation..." << std::endl;
    while (v_ry > 0 || time_step == 0) {
        step();
        std::cout << time_step << "," << v_ry << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Simulation ended." << std::endl;

    return 0;

}