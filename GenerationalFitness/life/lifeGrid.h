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

# include "../simulator.h"
# include "lifeSquare.h"



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
