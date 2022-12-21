#include <iostream>
#include "../include/Node.h"


Node::Node(int row, int col, int distance_traveled) {
    this->row = row;
    this->col = col;
    this->dist_traveled = distance_traveled;
}

Node::~Node() = default;

int Node::getRow() {
    return this->row;
}

int Node::getCol() {
    return this->col;
}

int Node::getDistanceTraveled() {
    return this->dist_traveled;
}

void Node::setDistanceTraveled(int distance_traveled) {
    this->dist_traveled = distance_traveled;
}

int Node::getEstimatedDist2Goal(Node *goal) {
    int manhattan_distance = (col - goal->getCol()) + (row - goal->getRow());
    int estimated_distance = dist_traveled + manhattan_distance;
    return abs(estimated_distance);
}

//--------------------------------                             