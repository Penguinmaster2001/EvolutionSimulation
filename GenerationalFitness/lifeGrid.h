/*
    Anthony Cieri

    LifeGrid extends the Simulator class to manage organisms that live on a grid.

    The grid is a 2D array of squares.
    Each square can hold one of:
        an organism
        a food source (one of several types)
        nothing

    
    The size of the grid is set in the constructor and cannot be changed.
 */

# ifndef LIFEGRID_H
# define LIFEGRID_H

# include "simulator.h"
# include "organism.h"
# include "lifeSquare.h"


/*
    LifeFood is the base class for all food sources in the LifeGrid.
    It is a virtual class and should be extended to create specific food sources.
 */
class LifeFood : public LifeSquareObject {

};



class LifeGrid : public Simulator {

};

# endif
