/*
    Anthony Cieri

    
    Organism is the base class for any kind of evolving creature.

    An organism has two parents, and is able to reproduce with
    another organism to create a new organism.

    It includes the basic fields and methods required for evolution:
        parents
            Stores references to parents of the organism, allows for tracking of ancestry

        Random empty constructor
            The constructor that takes no arguments is used to generate a new random organism
            This should be used for the first generation

        Parents constructor
            This constructor is used to create an organism with a set of parents
            This should be used for all generations after the first
        
        reproduce
            This method allows two organisms to reproduce and create a new organism

    This class should allow for derivative classes to manage the specifics of the organism
    or for a larger class to manage the specifics of many organisms
    
    In the future I hope to add asexual and other forms of reproduction
 */

# ifndef ORGANISM_H
# define ORGANISM_H

# include <vector>
# include <random>
# include <memory>

// Typedefs to make the shared pointers easier to read
typedef std::shared_ptr<Organism> OrganismPtr;
typedef std::vector<OrganismPtr> OrganismVector;

class Organism {
private:
    OrganismVector parents;

public:
    Organism();
    Organism(OrganismVector parents);

    virtual Organism reproduce(Organism other);
};

# endif
