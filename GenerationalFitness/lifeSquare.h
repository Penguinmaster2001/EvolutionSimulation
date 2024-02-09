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

typedef std::shared_ptr<LifeSquareObject> LifeSquareObjectPtr;
typedef std::shared_ptr<LifeSquare> LifeSquarePtr;
typedef std::array<LifeSquarePtr, 8> LifeSquareNeighborArray;

/*
    LifeSquareObject is the base class for all objects that can exist in a LifeSquare.
    It is a virtual class and should be extended to create specific objects.

    It must exist in a LifeSquare (it must hold a reference to its square).
 */
class LifeSquareObject {
private:
    LifeSquarePtr square;

public:
    LifeSquareObject(LifeSquarePtr square) : square(square) {};

    LifeSquarePtr getSquare() { return square; };

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

    // Stored counter-clockwise from the right
    LifeSquareNeighborArray neighbors;

public:
    LifeSquare(LifeSquareNeighborArray neighbors) : object(nullptr), neighbors(neighbors) {};

    void setObject(LifeSquareObjectPtr object) { this->object = object; };
    LifeSquareObjectPtr getObject() { return object; };
};

# endif
