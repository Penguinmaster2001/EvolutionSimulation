/*
    Anthony Cieri 2024



 */

# ifndef LIFEFOOD_H
# define LIFEFOOD_H

# include "lifeSquare.h"


/*
    Each food type requires different stomach types

    When an organim attempts to eat a food of the wrong type, it's
    either harmful or less efficient
 */
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
    LifeFood(LifeSquarePtr square, int type, int init_amount)
        : LifeSquareObject(square), food_type(type), food_amount(init_amount) {};

    // Called by the LifeGrid to update the food source
    virtual void update(LifeSquareObjectArray neighbors) override;

};

# endif
