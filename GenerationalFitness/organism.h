/*
    Anthony Cieri

    
    This file holds the Organism class and functions
 */

# ifndef ORGANISM_H
# define ORGANISM_H

# include <iostream>
# include <random>

class Organism {
private:
    float fitness;

    friend std::ostream& operator<<(std::ostream& os, const Organism& organism);

public:
    Organism() : fitness(0.5) {};
    Organism(float fitness);
    float get_fitness() const {return this->fitness;}
    void set_fitness(float fitness) {this->fitness = fitness;}

    Organism reproduce(Organism other);
};

# endif
