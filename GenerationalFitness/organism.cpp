#include "organism.h"

// Generate new random Organism
Organism::Organism()
{
    this->parents = std::vector<Organism*>();
}

// Generate Organism as a child with parents
Organism::Organism(std::vector<Organism *> parents)
{
    this->parents = parents;
}

// Generate Organism as a child of two parents
Organism Organism::reproduce(Organism other)
{
    std::vector<Organism*> parents = {this, &other};

    return Organism(parents);
}
