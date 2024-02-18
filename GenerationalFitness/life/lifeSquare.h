/*
    Anthony Cieri

    LifeSquare is the base class for all squares in the LifeGrid.

    This file also contains the base class for all objects that can exist in a LifeSquare.

    This could be easily modified to support some crazy topologies but I'm keeping this simple for now.
 */

# ifndef LIFESQUARE_H
# define LIFESQUARE_H

# include <memory>
# include <array>

# include "lifeSquareObject.h"

typedef std::shared_ptr<LifeSquare> LifeSquarePtr;
typedef std::array<LifeSquarePtr, 8> LifeSquareNeighborArray;


/*
    LifeSquare is the base class for all squares in the LifeGrid.

    It must hold a reference to its 8 neighbors
    (before the simulation starts so we have no chicken-egg problems).

    It may hold a reference to a single LifeSquareObject
 */
class LifeSquare {
private:
    LifeSquareObjectPtr object;

    // Stored counter-clockwise from the right
    LifeSquareNeighborArray neighbors;

public:
    LifeSquare(LifeSquareNeighborArray neighbors) : object(nullptr), neighbors(neighbors) {};

    void set_object(LifeSquareObjectPtr object) { this->object = object; };
    void remove_object() { this->object = nullptr; };

    LifeSquareObjectPtr get_object() { return object; };

    LifeSquareObjectType get_object_type() { return object->get_object_type(); };

    LifeSquareNeighborArray get_neighbors() { return neighbors; };

    bool is_empty() { return object == nullptr; };
};

# endif
