#include <iostream>
#include "../include/NodeList.h"

NodeList::NodeList() {
    for (auto &node: nodes)
        node = nullptr;
    this->length = 0;
}

NodeList::~NodeList() {
    for (auto &node: nodes)
        delete node;
}

NodeList::NodeList(NodeList &other) {
    for (int i = 0; i < this->length; i++) this->nodes[i] = new Node(*other.nodes[i]);
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