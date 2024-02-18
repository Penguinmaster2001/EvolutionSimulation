/*
    Anthony Cieri

    LifeSquare is the base class for all squares in the LifeGrid.

    Right now there's only one type of square.

    The squares should be thought more of a surface than a container.
    This means the objects on the squares have the responsiblitity of
    updating the square they are on.

    This could be easily modified to support some crazy topologies but I'm keeping this simple for now.
 */

# pragma once
# include <memory>
# include <array>

class LifeSquare;
class LifeSquareObject;

typedef std::shared_ptr<LifeSquare> LifeSquarePtr;
typedef std::shared_ptr<LifeSquareObject> LifeSquareObjectPtr;

typedef std::array<LifeSquarePtr, 8> LifeSquareNeighborArray;


enum LifeSquareObjectType {
    NONE,
    ORGANISM,
    FOOD
};


/*
    LifeSquare is the base class for all squares in the LifeGrid.

    It must hold a reference to its 8 neighbors
    (before the simulation starts so we have no chicken-egg problems).

    It may hold a reference to a single LifeSquareObject
 */
class LifeSquare {
private:
    LifeSquareObjectPtr object;
    LifeSquareObjectType object_type;

    // Stored counter-clockwise from the right
    LifeSquareNeighborArray neighbors;

public:
    LifeSquare(LifeSquareNeighborArray neighbors) : object(nullptr), neighbors(neighbors) {};

    void set_object(LifeSquareObjectPtr object, LifeSquareObjectType object_type) { this->object = object; this->object_type = object_type; };
    void remove_object() { this->object = nullptr; object_type = LifeSquareObjectType::NONE; };

    LifeSquareObjectPtr get_object() { return object; };

    LifeSquareObjectType get_object_type() { return object_type; };

    LifeSquareNeighborArray get_neighbors() { return neighbors; };

    bool is_occupied() { return object != nullptr; };
    bool is_empty() { return object == nullptr; };
};
