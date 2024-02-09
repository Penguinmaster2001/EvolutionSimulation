
/*
    Anthony Cieri

    This holds the stuff that manages everything
 */

#ifndef SIMULATOR_H
#define SIMULATOR_H

# include "generation.h"

# include <iostream>
# include <string>


class Simulator {
private:
    int num_organisms;
    int num_generations;
    Generation current_generation;

public:
    Simulator(int num_organisms, int num_generations);

    void run();
};

#endif
