#include "organism.h"

Organism::Organism(int fitness)
{
    this->fitness = fitness;
}

int Organism::get_fitness()
{
    return this->fitness;
}

void Organism::set_fitness(int fitness)
{
    this->fitness = fitness;
}

Organism Organism::reproduce(Organism other)
{
    // The fitness of the offspring is the average of the parents' fitness for now
    // TODO: add mutation
    int new_fitness = (this->fitness + other.get_fitness()) / 2;
    Organism offspring(new_fitness);
    return offspring;
}
