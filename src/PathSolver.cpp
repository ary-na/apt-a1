#include <iostream>
#include <algorithm>
#include "../include/PathSolver.h"

PathSolver::PathSolver() {
    std::cout << "-- Inside PathSolver Constructor --" << std::endl;
    this->nodes_explored = nullptr;
    this->start_node = new Node(0,0,0);
    this->goal_node = new Node(0,0,0);
}

PathSolver::~PathSolver() {
    std::cout << "-- Inside PathSolver Destructor --" << std::endl;
    delete nodes_explored;
    delete start_node;
    delete goal_node;
}

void PathSolver::forwardSearch(Env env) {

    // Initialise Open and Closed lists
    auto *P = new NodeList;
    auto *C = new NodeList;

    // Add start location node to open list
    P->addElement(this->start_node);

    // Select initial Node
    Node *p = P->getNode(0);

    do {
        int tempEstimatedDistance = INT32_MAX;
        for (int i = 0; i < P->getLength(); i++)
            // Condition: Selected Node p is not in closed List C and has the least estimated distance to goal Node
            if (!nodeExists(C, P->getNode(i)) && P->getNode(i)->getEstimatedDist2Goal(this->goal_node) <= tempEstimatedDistance) {
                tempEstimatedDistance = P->getNode(i)->getEstimatedDist2Goal(this->goal_node);
                p = P->getNode(i);
                // Reachable positions from Node p
                for (int j = 0; j < 8; j = j + 2)
                    if (env[reachablePositions(p)[j]][reachablePositions(p)[j + 1]] != SYMBOL_WALL) {
                        auto *node = new Node(reachablePositions(p)[j], reachablePositions(p)[j + 1], p->getDistanceTraveled() + 1);
                        if (!nodeExists(P, node)) P->addElement(node);
                    }
                C->addElement(p);
            }
    } while ((!(p->getCol() == this->goal_node->getCol() && p->getRow() == this->goal_node->getRow()))); // Loop condition: selected Node does not equal to goal Node
    this->nodes_explored = new NodeList(*C);

    // To be deleted
    for (int i = 0; i < P->getLength(); i++)
        std::cout << P->getNode(i)->getRow() << " | " << P->getNode(i)->getCol() << " ---- "
                  << P->getNode(i)->getDistanceTraveled() << " ---- "
                  << P->getNode(i)->getEstimatedDist2Goal(P->getNode(P->getLength() - 1)) << std::endl;

    std::cout << "---------------------------------------" << std::endl;

    for (int i = 0; i < C->getLength(); i++)
        std::cout << C->getNode(i)->getRow() << " | " << C->getNode(i)->getCol() << " ---- "
                  << C->getNode(i)->getDistanceTraveled() << " ---- "
                  << C->getNode(i)->getEstimatedDist2Goal(C->getNode(C->getLength() - 1)) << std::endl;
}

NodeList *PathSolver::getNodesExplored() {
    return this->nodes_explored;
}

NodeList *PathSolver::getPath(Env env) {

    // Initialise Closed and Path lists
    NodeList *C = this->getNodesExplored();
    auto *P = new NodeList;

    // Start Node
    Node *startNode = C->getNode(0);

    // Selected Node (Initially Goal Node)
    Node *p = C->getNode(C->getLength() - 1);

    // Goal Node distance travelled
    int L = C->getNode(C->getLength() - 1)->getDistanceTraveled();

    // Add selected Node to Path list
    P->addElement(new Node(p->getRow(), p->getCol(), p->getDistanceTraveled()));

    do {
        // Reachable positions from Node p
        for (int j = 0; j < 8; j = j + 2)
            // Condition: Position is not SYMBOL_WALL
            if (env[reachablePositions(p)[j]][reachablePositions(p)[j + 1]] != SYMBOL_WALL)
                for (int i = C->getLength() - 1; i >= 0; i--)
                    // Condition: Reachable Node exists in closed List AND has dist_travelled one less than selected Node
                    if (C->getNode(i)->getRow() == reachablePositions(p)[j] &&
                        C->getNode(i)->getCol() == reachablePositions(p)[j + 1] &&
                        C->getNode(i)->getDistanceTraveled() == L - 1 && !nodeExists(P, C->getNode(i))) {
                        // Add p to Path list
                        P->addElement(new Node(C->getNode(i)->getRow(), C->getNode(i)->getCol(),
                                               C->getNode(i)->getDistanceTraveled()));
                        // Update distance travelled and selected Node
                        L = C->getNode(i)->getDistanceTraveled();
                        p = C->getNode(i);
                    }
    } while (p != startNode); // Loop condition: selected Node does not equal to start Node

    // To be deleted
    for (int i = 0; i < P->getLength(); i++)
        std::cout << P->getNode(i)->getRow() << " | " << P->getNode(i)->getCol() << " ---- "
                  << P->getNode(i)->getDistanceTraveled() << " ---- "
                  << P->getNode(i)->getEstimatedDist2Goal(P->getNode(P->getLength() - 1)) << std::endl;
    return P;
}

Node *PathSolver::getStartNode() const {
    return start_node;
}

Node *PathSolver::getGoalNode() const {
    return goal_node;
}

bool PathSolver::nodeExists(NodeList *nodeList, Node *node) {
    for (int i = 0; i < nodeList->getLength(); i++) {
        if (nodeList->getNode(i)->getRow() == node->getRow() && nodeList->getNode(i)->getCol() == node->getCol())
            return true;
    }
    return false;
}

int *PathSolver::reachablePositions(Node *node) {
    int q[] = {node->getRow() - 1, node->getCol(), node->getRow() + 1, node->getCol(),
               node->getRow(), node->getCol() - 1, node->getRow(), node->getCol() + 1};
    return q;
}

//-----------------------------