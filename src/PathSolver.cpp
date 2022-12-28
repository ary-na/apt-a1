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

    // Start location Node
    auto *startNode = new Node(5, 1, 0);

    // Goal location Node
    auto *goalNode = new Node(11, 5, 0);

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
                }
        }

        // Reachable positions from Node p
        int q[] = {p->getRow() - 1, p->getCol(), p->getRow() + 1, p->getCol(), p->getRow(), p->getCol() - 1,
                   p->getRow(), p->getCol() + 1};

        for (int i = 0; i < 8; i = i + 2) {
            if (env[q[i]][q[i + 1]] != SYMBOL_WALL) {
                auto *node = new Node(q[i], q[i + 1], p->getDistanceTraveled() + 1);
                if (!nodeExists(P, node))
                    P->addElement(node);
            }
        }
        C->addElement(p);
    }
    this->nodes_explored = new NodeList(*C);
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