#include <iostream>
#include "../include/NodeList.h"

NodeList::NodeList() {
    std::cout << "-- Inside NodeList Constructor --" << std::endl;
    for (auto &node: nodes) node = new Node(0, 0, 0);
    this->length = 0;
}

NodeList::~NodeList() {
    std::cout << "-- Inside NodeList Destructor --" << std::endl;
    for (auto &node: nodes) delete node;
}

NodeList::NodeList(NodeList &other) {
    std::cout << "-- Inside NodeList Copy Constructor --" << std::endl;
    for (int i = 0; i < NODE_LIST_ARRAY_MAX_SIZE; i++) this->nodes[i] = new Node(*other.nodes[i]);
    this->length = other.length;
}

int NodeList::getLength() const {
    return this->length;
}

void NodeList::addElement(Node *newPos) {
    this->nodes[this->length] = newPos;
    this->length++;
}

Node *NodeList::getNode(int i) {
    return this->nodes[i];
}