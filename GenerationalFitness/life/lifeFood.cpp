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
    // Count the number of neighboring food sources
    int neighboring_food_count = 0;
    for (LifeSquareObjectPtr neighbor : neighbors)
    {
        if (neighbor->get_object_type() == LifeSquareObjectType::FOOD)
        {
            neighboring_food_count++;
        }
    }

    // If there's too many food sources around, then deactivate
    if (neighboring_food_count >= 4)
    {
        deactivate();
        return;
    }

    food_amount += neighboring_food_count;

    // If there's enough food, then attempt to spread to a random neighbor
    if (food_amount > FOOD_SPREAD_THRESHOLD)
    {
        LifeSquarePtr spread_square = neighbors[rand() % 8];

        if (spread_square->is_empty())
        {
            LifeFoodSource new_food_source = LifeFoodSource(spread_square, food_type, food_amount / 2);

            spread_square->set_object(std::make_shared<LifeFoodSource>(new_food_source));
            food_amount /= 2;
        }
    }
}



LifeFood LifeFoodSource::give_food(int amount)
{
    LifeFood to_give;
    to_give.type = food_type;

    // If there's no food, then deactivate and return 0 food
    if (food_amount <= 0)
    {
        deactivate();
        to_give.food_amount = 0;
        return to_give;
    }

    // If there's not enough food, then give all the food and return
    if (food_amount < amount)
    {
        to_give.food_amount = food_amount;
        food_amount = 0;
        return to_give;
    }

    // Otherwise, give the requested amount and return
    to_give.food_amount = amount;
    food_amount -= amount;
    return to_give;
}
