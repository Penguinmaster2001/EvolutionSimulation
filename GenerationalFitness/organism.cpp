#include "organism.h"

// Generate new random Organism
Organism::Organism()
{
    this->parents = OrganismVector();
}

// Generate Organism as a child with parents
Organism::Organism(OrganismVector parents)
{
    this->parents = parents;
}

// Generate Organism as a child of two parents
Organism Organism::reproduce(Organism other)
{
    OrganismVector parents = {this, &other};

    return Organism(parents);
}
