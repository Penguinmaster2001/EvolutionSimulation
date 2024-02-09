/*
    Anthony Cieri

    This class extends the organism class to include methods specific to living on a LifeGrid.
    It also extends the LifeSquareObject class so it can exist in a LifeSquare.

    Such methods include:
        - moving
        - eating
        - dying
    
    Method overrides include:
        - constructor
        - reproducing
 */



# ifndef LIFEORGANISM_H
# define LIFEORGANISM_H

# include "organism.h"
# include "lifeSquare.h"

class LifeOrganism : public Organism, public LifeSquareObject {

};

# endif