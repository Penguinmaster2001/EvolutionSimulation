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


// Crazy how these are the foods I came up with
enum LifeFoodType {
    CHAMOMILE,
    ARUGULA,
    WATERMELON,
    SALSIFY,
    DRAGONFRUIT
};

/*
    LifeFood is the base class for all food sources in the LifeGrid.
    It is a virtual class and should be extended to create specific food sources.

    I'm going to keep this one super simple.
 */
class LifeFood : public LifeSquareObject {
private:
    int food_amount;
    int food_type;

public:
    LifeFood(LifeSquarePtr square) : LifeSquareObject(square) {};

    // Called by the LifeGrid to update the food source
    virtual void update(LifeSquareObjectArray neighbors) override;

};



typedef std::vector<std::vector<LifeSquarePtr>> LifeSquareGrid;

class LifeGrid : public Simulator {
private:
    int length, width;
    LifeSquareGrid grid;

    void update_grid();


public:
    LifeGrid(int length, int width, int num_organisms);

    int get_length() { return length; };
    int get_width() { return width; };

    // Update all the squares in the grid, also do some other stuff idk yet
    void run() override;
};

# endif
