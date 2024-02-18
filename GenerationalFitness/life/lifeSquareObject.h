
/*
    Anthony Cieri 2024

    LifeSquareObject is the base class for all objects that can exist in a LifeSquare.
    It is a virtual class and should be extended to create specific objects.

    It must exist in a LifeSquare (it must hold a reference to its square).

    It must have an update method that takes an array of its neighbors.
 */

# pragma once
# include "lifeSquare.h"




class LifeSquareObject {
private:
    LifeSquarePtr square;
    LifeSquareObjectType object_type;
    bool active = true;

public:
    LifeSquareObject(LifeSquarePtr square, LifeSquareObjectType object_type)
        : square(square), object_type(object_type) {};

    LifeSquarePtr get_square() { return square; };

    // Called by the LifeGrid to update the object
    virtual void update(LifeSquareNeighborArray neighbors);

    LifeSquareObjectType get_object_type() { return object_type; };

    bool is_active() { return active; };

    // Remove from the parent square and set active to false
    void deactivate();
};
