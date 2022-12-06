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
    int getRow();

    // get column-coordinate of the node
    int getCol();

    //getter and setter for distance traveled
    int getDistanceTraveled();

    void setDistanceTraveled(int dist_traveled);

    //getter for estimated dist to goal - need to return -> Manhattan distance + distance traveled
    int getEstimatedDist2Goal(Node *goal);

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */


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

#endif //COSC_ASSIGN_ONE_NODE