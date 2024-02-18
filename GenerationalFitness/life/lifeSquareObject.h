
/*
    Anthony Cieri 2024

    LifeSquareObject is the base class for all objects that can exist in a LifeSquare.
    It is a virtual class and should be extended to create specific objects.

    It must exist in a LifeSquare (it must hold a reference to its square).

    It must have an update method that takes an array of its neighbors.
 */

# ifndef LIFESQUAREOBJECT_H
# define LIFESQUAREOBJECT_H

# include <memory>
# include <array>

# include "lifeSquare.h"

typedef std::shared_ptr<LifeSquareObject> LifeSquareObjectPtr;
typedef std::array<std::shared_ptr<LifeSquareObject>, 8> LifeSquareObjectArray;


enum LifeSquareObjectType {
    NONE,
    ORGANISM,
    FOOD
};


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
    virtual void update(LifeSquareObjectArray neighbors);

    LifeSquareObjectType get_object_type() { return object_type; };

    bool is_active() { return active; };

    // Remove from the parent square and set active to false
    void deactivate();
};

# endif
