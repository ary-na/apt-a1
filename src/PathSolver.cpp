#include <iostream>
#include <algorithm>
#include "../include/PathSolver.h"

PathSolver::PathSolver() {
    this->nodes_explored = nullptr;
}

PathSolver::~PathSolver() {
    delete nodes_explored;
}

void PathSolver::forwardSearch(Env env) {

    // Start location
    std::cout << env[5][1] << std::endl;
    auto *startNode = new Node(5, 1, 0);

    // Goal location
    std::cout << env[11][5] << std::endl;
    auto *goalNode = new Node(11, 5, 0);

    // Open list
    auto *P = new NodeList;

    // Add Pointer to start node to the list
    P->addElement(startNode);

    // Closed list
    auto *C = new NodeList;

    Node *p = P->getNode(0);

    do {
        int pEstimatedDistance = p->getEstimatedDist2Goal(goalNode);

        for (int i = 0; i < P->getLength(); i++) {
            int smallestEstimatedDistance = P->getNode(i)->getEstimatedDist2Goal(goalNode);
            if (!nodeExists(C, P->getNode(i))) {
                if (pEstimatedDistance >= smallestEstimatedDistance || smallestEstimatedDistance == 0) {
                    p = P->getNode(i);
                    pEstimatedDistance = smallestEstimatedDistance;

                    int row = p->getRow();
                    int col = p->getCol();

                    int q[] = {row - 1, col, row + 1, col, row, col - 1, row, col + 1};

                    for (int j = 0; j < 8; j = j + 2) {
                        if (env[q[j]][q[j + 1]] != SYMBOL_WALL) {
                            auto *node = new Node(q[j], q[j + 1], p->getDistanceTraveled() + 1);
                            if (!nodeExists(P, node)) {
                                P->addElement(node);
                            }
                        }
                    }

                    goalNode->setDistanceTraveled(p->getDistanceTraveled());
                    C->addElement(p);
                }
            }
        }

    } while (p != goalNode);

    for (int i = 0; i < C->getLength(); i++) {
        std::cout << C->getNode(i) << std::endl;
    }
}

NodeList *PathSolver::getNodesExplored() {
    return this->nodes_explored;
}

NodeList *PathSolver::getPath(Env env) {
    // TODO
}

bool PathSolver::nodeExists(NodeList *nodeList, Node *node) {
    for (int i = 0; i < nodeList->getLength(); i++) {
        if (nodeList->getNode(i)->getRow() == node->getRow() && nodeList->getNode(i)->getCol() == node->getCol())
            return true;
    }
    return false;
}

//-----------------------------