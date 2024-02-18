#include "lifeSquareObject.h"

void LifeSquareObject::deactivate()
{
    active = false;

    square->remove_object();

    square = nullptr;
}
