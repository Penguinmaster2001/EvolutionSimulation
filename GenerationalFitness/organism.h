/*
    Anthony Cieri

    
    This file holds the Organism class and functions
 */

# ifndef ORGANISM_H
# define ORGANISM_H

class Organism {
private:
    int fitness;

public:
    Organism(int fitness);
    int get_fitness();
    void set_fitness(int fitness);

    Organism reproduce(Organism other);
};

# endif
