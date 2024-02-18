#include "lifeSquareObject.h"

void LifeSquareObject::update(LifeSquareNeighborArray neighbors)
{
    int neighbor_count = 0;

    for (LifeSquarePtr neighbor : neighbors)
    {
        if (neighbor->get_object_type() == object_type)
        {
            neighbor_count++;
        }
    }

    if (neighbor_count >= 4)
    {
        deactivate();
    }

    if (neighbor_count <= 1)
    {
        deactivate();
    }
}

void LifeSquareObject::deactivate()
{
    active = false;

    square->remove_object();

    square = nullptr;
}
