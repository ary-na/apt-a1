#include "../include/Node.h"


Node::Node(int row, int col, int distance_traveled) {
    this->row = row;
    this->col = col;
    this->dist_traveled = distance_traveled;
}

Node::~Node() = default;

int Node::getRow() const {
    return this->row;
}

int Node::getCol() const {
    return this->col;
}

int Node::getDistanceTraveled() const {
    return this->dist_traveled;
}

void Node::setDistanceTraveled(int distance_traveled) {
    this->dist_traveled = distance_traveled;
}

int Node::getEstimatedDist2Goal(Node *goal) const {
    int manhattan_distance = (this->col - goal->getCol()) + (this->row - goal->getRow());
    int estimated_distance = this->dist_traveled + manhattan_distance;
    return abs(estimated_distance);
}

//--------------------------------                             