#include "organism.h"

Organism::Organism(float fitness)
{
    this->fitness = fitness;
}



Organism Organism::reproduce(Organism other)
{
    // The fitness of the offspring is the average of the parents' fitness for now
    // TODO: add mutation
    float new_fitness = (this->fitness + other.get_fitness()) / 2;
    Organism offspring(new_fitness);
    return offspring;
}



std::ostream &operator<<(std::ostream &os, const Organism &organism)
{
    os << "Organism: " << organism.get_fitness() << " fitness";
    return os;
}
