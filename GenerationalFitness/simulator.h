
/*
    Anthony Cieri

    This holds the stuff that manages everything
 */

#ifndef SIMULATOR_H
#define SIMULATOR_H

# include <iostream>


class Simulator {
private:
    int num_organisms;
    int num_generations;

public:
    Simulator(int num_organisms, int num_generations);

    void run();
};

#endif
