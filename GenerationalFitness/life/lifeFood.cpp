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
    int neighboring_food_count = 0;

    for (LifeSquareObjectPtr neighbor : neighbors)
    {
        if (neighbor->get_object_type() == LifeSquareObjectType::FOOD)
        {
            neighboring_food_count++;
        }
    }

    if (neighboring_food_count >= 4)
    {
        deactivate();
    }

    food_amount += neighboring_food_count;
}

LifeFood LifeFoodSource::give_food(int amount)
{
    if (food_amount <= 0)
    {
        deactivate();
    }

    LifeFood to_give;
    to_give.type = food_type;

    if (food_amount > amount)
    {
        to_give.food_amount = amount;
        food_amount -= amount;

        return to_give;
    }

    to_give.food_amount = food_amount;
    food_amount = 0;
    return to_give;
}
