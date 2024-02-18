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
    
    This should kind of follow the rules of Conway's Game of Life:
        Death by underpopulation (Lack of food for some time? Lack of interaction with other organisms?)
        Death by overpopulation (Too much food? Too much interaction with other organisms?)

        Maybe instead of death immediately, the organism will attempt to move to a better square to live in.

        Birth by reproduction (3 neighbors???? Might have to make that just 2 whoops)
 */



# ifndef LIFEORGANISM_H
# define LIFEORGANISM_H

# include "../organism.h"
# include "lifeSquare.h"

class LifeOrganism : public Organism, public LifeSquareObject {

};

# endif