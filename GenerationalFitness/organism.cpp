#include "organism.h"

// Generate new random Organism
Organism::Organism()
{
    
}

Organism::Organism(float fitness)
{
    this->fitness = fitness;
}



Organism Organism::reproduce(Organism other)
{
    // The fitness of the offspring is the average of the parents' fitness plus some randomness
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> normal_dist(0, 0.5);

    float new_fitness = ((this->fitness + other.get_fitness()) / 2) + normal_dist(gen);
    Organism offspring(new_fitness);
    return offspring;
}



std::ostream &operator<<(std::ostream &os, const Organism &organism)
{
    os << "Organism: " << organism.get_fitness() << " fitness";
    return os;
}
