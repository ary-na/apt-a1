#include <iostream>
#include <algorithm>
#include "../include/PathSolver.h"

PathSolver::PathSolver() {
    // TODO
}

PathSolver::~PathSolver() {
    // TODO
}

void PathSolver::forwardSearch(Env env) {

    // Start location
    auto startLocation = env[5][1];
    auto *startNode = new Node(5, 1, 0);

    // Goal location
    auto goalLocation = env[11][5];
    auto *goalNode = new Node(11, 5, 0);

    // Open list
    auto *p = new NodeList;

    // Closed list
    auto *c = new NodeList;

    // Add Pointer to start node to the list
    p->addElement(startNode);
    auto selected_node = p->getNode(0);

    do {
        int smallestEstimatedDistance = selected_node->getEstimatedDist2Goal(goalNode);

        for (int i = 0; i < p->getLength(); i++) {
            int estimatedDistance = p->getNode(i)->getEstimatedDist2Goal(goalNode);
            if (estimatedDistance <= smallestEstimatedDistance && !nodeExists(c, p->getNode(i))) {
                smallestEstimatedDistance = estimatedDistance;
                selected_node = p->getNode(i);
            }
        }

        int row = selected_node->getRow();
        int col = selected_node->getCol();

        int q[] = {row - 1, col, row + 1, col, row, col - 1, row, col + 1};

        for (int i = 0; i < 8; i = i + 2) {
            if (env[q[i]][q[i + 1]] == SYMBOL_EMPTY) {
                auto *node = new Node(q[i], q[i + 1], selected_node->getDistanceTraveled() + 1);
                if (!nodeExists(p, node)) {
                    p->addElement(node);
                }
            }
        }

        c->addElement(selected_node);

    } while (selected_node->getRow() != goalNode->getRow() && selected_node->getCol() != goalNode->getCol());

    for(int i = 0; i < c->getLength(); i++){
        std::cout << c[i].getNode(i) << std::endl;
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
        if (nodeList->getNode(i) == node)
            return true;
    }
    return false;
}

//-----------------------------