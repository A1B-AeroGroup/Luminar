#ifndef FORCE_H
#define FORCE_H

enum plane {
    x, y, z,
};

class force {
    public:
        /**
         * @brief Construct a new force object.
         * 
         * @param x magnitude in the x.
         * @param y magnitude in the y.
         * @param z magnitude in the z.
         */
        force(double x, double y, double z);

        /**
         * @brief Set the magnitude and direction of the
         * force.
         * 
         * @param p Plane on which the force acts on! 
         * @param f magnitude of the force.
         * @return double the last force.
         */
        double setForce(plane p, double f);

        /**
         * @brief increments the force in plane p
         * according to the f applied.
         * 
         * @param p plane to change.
         * @param f magnitude of f.
         */
        void incrementForce(plane p, double f);
        
        /**
         * @brief sets the magntidue.
         * 
         * @param m pointer to pointer to magnitude. 
         */
        void getMagnitude(double **m);

        /**
         * @brief Get the magnitude of the force in plane
         * p.
         * 
         * @param p plane to get the force magnitude in. 
         * @return double magnitude of the force.
         */
        double getForce(plane p);
    private:
        // force magnitude in the x, y, and z planes.
        double x;
        double y;
        double z;
};

#endif