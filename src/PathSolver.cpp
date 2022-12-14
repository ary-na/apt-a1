#include <iostream>
#include "../include/PathSolver.h"

PathSolver::PathSolver() {
    // TODO
}

PathSolver::~PathSolver() {
    // TODO
}

void PathSolver::forwardSearch(Env env) const {




    auto *p = new NodeList();
    // Add Pointer to start node to the list
    p->addElement(this->getStartNode());

    do{
        for (int i = 0; i < p->getLength(); i++) {
            int estimatedDistance = p->getNode(i)->getEstimatedDist2Goal(this->getGoalNode());
            p->getNode(i)->getRow()+1;
        }
    }
    while(p->getNode(p->getLength()) != this->getGoalNode());


}

NodeList *PathSolver::getNodesExplored() {
    return this->nodes_explored;
}

NodeList *PathSolver::getPath(Env env) {
    // TODO
}

Node *PathSolver::getStartNode() const {
    return start_node;
}

void PathSolver::setStartNode(Node *startNode) {
    start_node = startNode;
}

Node *PathSolver::getGoalNode() const {
    return goal_node;
}

void PathSolver::setGoalNode(Node *goalNode) {
    goal_node = goalNode;
}

//-----------------------------