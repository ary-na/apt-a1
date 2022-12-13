#include <iostream>
#include "../include/NodeList.h"

NodeList::NodeList() {
    this->length = 0;
}

NodeList::~NodeList() {
        delete [] *nodes;
}

NodeList::NodeList(NodeList &other) {
    this->length = other.length;
    for(int i = 0; i <= other.length; i++) this->nodes[i] = other.nodes[i];
}

int NodeList::getLength() const {
    return this->length;
}

void NodeList::addElement(Node *newPos) {
    this->nodes[this->getLength() + 1] = newPos;
}

Node *NodeList::getNode(int i) {
    return nodes[i];
}