#ifndef COSC_ASSIGN_ONE_PATHSOLVER
#define COSC_ASSIGN_ONE_PATHSOLVER

#include "Node.h"
#include "NodeList.h"
#include "Types.h"

class PathSolver {
public:
    /*                                           */
    /* DO NOT MODIFY ANY CODE IN THIS SECTION    */
    /*                                           */

    // Constructor/Destructor
    PathSolver();

    ~PathSolver();

    // Execute forward search algorithm
    // To be implemented for Milestone 2
    void forwardSearch(Env env);

    // Get a DEEP COPY of the explored NodeList in forward search
    // To be implemented for Milestone 2
    NodeList *getNodesExplored();

    // Execute backtracking and Get a DEEP COPY of the path the 
    // robot should travel
    // To be implemented for Milestone 3
    NodeList *getPath(Env env);

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */

    // Get start and goal Nodes
    Node *getStartNode() const;

    Node *getGoalNode() const;

    // Search Node Lists for existing nodes
    static bool nodeExists(NodeList *nodeList, Node *node);

    // Return an array of reachable positions from selected Node
    static int *reachablePositions(Node *node);

private:
    /*                                           */
    /* DO NOT MODIFY THESE VARIABLES             */
    /*                                           */

    // Nodes explored in forward search algorithm
    NodeList *nodes_explored;

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */

    Node *start_node;
    Node *goal_node;
};


#endif //COSC_ASSIGN_ONE_PATHSOLVER