
/*
    Anthony Cieri

    This holds the stuff that manages everything
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

    void run();
};

#endif
