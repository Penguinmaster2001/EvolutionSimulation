
/*
    Anthony Cieri

    Simulator is the base class of managers of the simulation of evolution of organisms.
    It must hold a vector of organisms and run the simulation.

    I will add more to this class in the future as needed.
 */

#ifndef SIMULATOR_H
#define SIMULATOR_H

# include "organism.h"

# include <iostream>
# include <string>
# include <memory>


class Simulator {
private:
    int num_organisms;
    OrganismVector organisms;

public:
    Simulator(int num_organisms);

    virtual void run();
};

#endif
