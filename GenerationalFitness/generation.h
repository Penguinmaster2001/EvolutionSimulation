/*
    Anthony Cieri

    
    This file holds the Generation class and functions
 */

# ifndef GENERATION_H
# define GENERATION_H

# include "organism.h"

# include <vector>
# include <random>

class Generation {
private:
    std::vector<Organism> organisms;

    std::vector<Organism> generate_random_organisms(int num_organisms);

public:
    Generation(std::vector<Organism> organisms);
    Generation(int num_organisms);

    std::vector<Organism> get_organisms();
    void set_organisms(std::vector<Organism> organisms);

    Generation create_next_generation();
};

# endif
