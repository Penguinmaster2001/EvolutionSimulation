/*
    Anthony Cieri 2024

    This file contains the life food source and types
 */

# pragma once
# include <random>

# include "lifeSquareObject.h"


# define FOOD_SPREAD_THRESHOLD 20

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



// What the source will give
struct LifeFood {
    int food_amount;
    LifeFoodType type;
};



/*
    LifeFood is the base class for all food sources in the LifeGrid.
    It is a virtual class and should be extended to create specific food sources.

    I'm going to keep this one super simple.
 */
class LifeFoodSource : public LifeSquareObject {
private:
    LifeFoodType food_type;
    int food_amount;

public:
    LifeFoodSource(LifeSquarePtr square, LifeFoodType food_type, int init_amount)
        : LifeSquareObject(square, FOOD), food_type(food_type), food_amount(init_amount) {};

    // Called by the LifeGrid to update the food source
    void update(LifeSquareNeighborArray neighbors) override;

    // Called when something eats the food
    LifeFood give_food(int amount);
};
