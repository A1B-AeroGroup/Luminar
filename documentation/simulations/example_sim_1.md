# Example Simulation 1: Does the egg break?
## *Does the egg break? This simulation will let us know*?
***
The rocket is simply a conduit through which companies can launch items into space. This means that the payload carried by the rockets is the most rocket companies' most valuable asset - not counting the rocket of course.

But just how secure do you have to make the rocket? ***The egg test will let us know***!

***
## Physical Attributes of an Object
***
``` c++
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
```
The code above is how we are choosing to represent our rocket! We have selected the 3 basic kinematic descriptors of an object: <mark>Acceleration, Velocity, and Displacement</mark>.

***
## Rocket Motor, but in software?
***
``` c++
/* motor variables (G38FJ) */
double impulse = 87.7; // Ns
double burn = 2.2; // s
```
The code above represents an AeroTech G38FJ motor whose net impulse and burntime are known. In an ideal scenario, you'd be able to have accurate millisecond resolution data about the rocket's impulse as a function of time, but in this case we are having to approximate!
***
## The Simulation
***
```C++
/* simulation variables */
unsigned int time_step = 0;
unsigned int time_delta = 1;
unsigned int total_time = 0;
bool egg_broke = false;
```
The variables that keep track of the simulation are noted above. This is a <em>very</em> stripped down version of what an actual simulation would look like! 
```C++
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
```
The function above steps through the various stages of the simulation, this method essentially applies an acceleration due to the motor's impulse to the rocket and then later calculates the foce imposed on the egg due to the changes in velocity (i.e., impulse). 

It was determined through a quick google search that an egg could sustain up to 24.5 N of force before breaking, and this is reflected in the if statement near the end of the function.
***
## Next Steps?
***
There are a couple of things that must be taken into consideration when looking at this simulation! 
1. This is a simple simulation written without the use of a proper framework and <mark>without any abstractions</mark>!
2. The resolution of the simulation is not good at all! 
3. The physics have been severly simplified!

It is my goal to create a simulation framework that solves all of these issues and allows for a scalable solution to today's various problems in scientific computing.