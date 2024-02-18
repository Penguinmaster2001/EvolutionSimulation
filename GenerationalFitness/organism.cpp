#include "organism.h"

// Generate new random Organism
Organism::Organism()
{
    parents = OrganismVector();
}

// Generate Organism as a child with parents
Organism::Organism(OrganismVector parents)
{
    parents = parents;
}

// Generate Organism as a child of two parents
Organism Organism::reproduce(Organism other)
{
    OrganismVector parents = OrganismVector({this, &other});

    return Organism(parents);
}
