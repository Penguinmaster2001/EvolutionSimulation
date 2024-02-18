#include "lifeFood.h"



/*
    Each update, the food source will
        Grow
            This means some amount of food is added to food_amount
        
        Spread
            If food_amount is large enough, there is a chance another source will be created
        
        Die
            If there's too many food sources around the food source will die (like CGOL)
            Also if give_food() is called while food_amount is 0, the source will die

 */
void LifeFoodSource::update(LifeSquareObjectArray neighbors)
{



    this->food_amount++;
}

LifeFood LifeFoodSource::give_food(int amount)
{
    if (food_amount <= 0)
    {
        // TODO: Die somehow
    }

    LifeFood to_give;
    to_give.type = this->food_type;

    if (this->food_amount > amount)
    {
        to_give.food_amount = amount;
        this->food_amount -= amount;

        return to_give;
    }

    to_give.food_amount = this->food_amount;
    this->food_amount = 0;
    return to_give;
}
