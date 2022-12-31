#ifndef COSC_ASSIGN_ONE_NODE
#define COSC_ASSIGN_ONE_NODE

#include "Types.h"

class Node {
public:
    /*                                           */
    /* DO NOT MODIFY ANY CODE IN THIS SECTION    */
    /*                                           */

    // Constructor/Destructor
    Node(int row, int col, int dist_traveled);

    ~Node();

    // get row-coordinate of the node
    int getRow() const;

    // get column-coordinate of the node
    int getCol() const;

    // getter and setter for distance traveled
    int getDistanceTraveled() const;

    void setDistanceTraveled(int dist_traveled);

    // getter for estimated dist to goal - need to return -> Manhattan distance + distance traveled
    int getEstimatedDist2Goal(Node *goal) const;

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */

    void setRow(int row);

    void setCol(int col);

private:
    /*                                           */
    /* DO NOT MODIFY THESE VARIABLES             */
    /*                                           */

    int row;
    int col;
    int dist_traveled;  // distance from start node

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */

};

#endif // COSC_ASSIGN_ONE_NODE