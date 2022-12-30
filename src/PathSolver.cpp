#include <iostream>
#include <algorithm>
#include "../include/PathSolver.h"

PathSolver::PathSolver() {
    std::cout << "-- Inside PathSolver Constructor --" << std::endl;
    this->nodes_explored = nullptr;
}

PathSolver::~PathSolver() {
    std::cout << "-- Inside PathSolver Destructor --" << std::endl;
    delete nodes_explored;
}

void PathSolver::forwardSearch(Env env) {

    // Start location Node
    auto *startNode = new Node(2, 8, 0);

    // Goal location Node
    auto *goalNode = new Node(12, 30, 0);

    // Initialise Open and Closed lists
    auto *P = new NodeList;
    auto *C = new NodeList;

    // Add start location node to open list
    P->addElement(startNode);

    // Select initial Node
    Node *p = P->getNode(0);

    while (!(p->getCol() == goalNode->getCol() && p->getRow() == goalNode->getRow())) {
        int tempEstimatedDistance = INT32_MAX;
        for (int i = 0; i < P->getLength(); i++) {
            if (!nodeExists(C, P->getNode(i)))
                if (P->getNode(i)->getEstimatedDist2Goal(goalNode) <= tempEstimatedDistance) {
                    tempEstimatedDistance = P->getNode(i)->getEstimatedDist2Goal(goalNode);
                    p = P->getNode(i);
                    // Reachable positions from Node p
                    int q[] = {p->getRow() - 1, p->getCol(), p->getRow() + 1, p->getCol(), p->getRow(), p->getCol() - 1,
                               p->getRow(), p->getCol() + 1};

                    for (int j = 0; j < 8; j = j + 2) {
                        if (env[q[j]][q[j + 1]] != SYMBOL_WALL) {
                            auto *node = new Node(q[j], q[j + 1], p->getDistanceTraveled() + 1);
                            if (!nodeExists(P, node))
                                P->addElement(node);
                        }
                    }
                    C->addElement(p);
                }
        }
    }
    this->nodes_explored = new NodeList(*C);


    for (int i = 0; i < P->getLength(); i++)
        std::cout << P->getNode(i)->getRow() << " | " << P->getNode(i)->getCol() << " ---- "
                  << P->getNode(i)->getDistanceTraveled() << " ---- " <<  P->getNode(i)->getEstimatedDist2Goal(P->getNode(P->getLength()-1)) << std::endl;

    std::cout << "---------------------------------------" << std::endl;

    for (int i = 0; i < C->getLength(); i++)
        std::cout << C->getNode(i)->getRow() << " | " << C->getNode(i)->getCol() << " ---- "
                  << C->getNode(i)->getDistanceTraveled() << " ---- " <<  C->getNode(i)->getEstimatedDist2Goal(C->getNode(C->getLength()-1)) << std::endl;
}

NodeList *PathSolver::getNodesExplored() {
    return this->nodes_explored;
}

NodeList *PathSolver::getPath(Env env) {

    auto C = this->getNodesExplored();

    // Start location Node
    auto *startNode = C->getNode(0);

    // NodeList path
    auto *P = new NodeList;

    int counter = C->getLength() - 1;
    Node *p = C->getNode(counter);
    int L = C->getNode(counter)->getDistanceTraveled();
    P->addElement(new Node(p->getRow(), p->getCol(), p->getDistanceTraveled()));

    do {
        // Reachable positions from Node p
        int q[] = {p->getRow() - 1, p->getCol(), p->getRow() + 1, p->getCol(), p->getRow(), p->getCol() - 1,
                   p->getRow(), p->getCol() + 1};
        for (int j = 0; j < 8; j = j + 2) {
            if (env[q[j]][q[j + 1]] != SYMBOL_WALL) {
                for (int i = C->getLength() - 1; i >= 0; i--) {
                    if (C->getNode(i)->getRow() == q[j] && C->getNode(i)->getCol() == q[j + 1] &&
                        C->getNode(i)->getDistanceTraveled() == L - 1 && !nodeExists(P, C->getNode(i))) {
                        P->addElement(new Node(C->getNode(i)->getRow(), C->getNode(i)->getCol(),
                                               C->getNode(i)->getDistanceTraveled()));
                        L = C->getNode(i)->getDistanceTraveled();
                        p = C->getNode(i);
                    }
                }
            }
        }
    } while (p != startNode);


    for (int i = 0; i < P->getLength(); i++)
        std::cout << P->getNode(i)->getRow() << " | " << P->getNode(i)->getCol() << " ---- "
                  << P->getNode(i)->getDistanceTraveled() << " ---- " <<  P->getNode(i)->getEstimatedDist2Goal(P->getNode(P->getLength()-1)) << std::endl;


    return C;
}

bool PathSolver::nodeExists(NodeList *nodeList, Node *node) {
    for (int i = 0; i < nodeList->getLength(); i++) {
        if (nodeList->getNode(i)->getRow() == node->getRow() && nodeList->getNode(i)->getCol() == node->getCol())
            return true;
    }
    return false;
}

//-----------------------------