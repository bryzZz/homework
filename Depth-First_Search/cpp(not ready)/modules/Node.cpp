#include "Node.h"
#include <set>

Node::Node(int value)
{
    this->value = value;
    this->visited = false;
}

void Node::connect(Node *node)
{
    this->connections.push_back(node);

    // node->connections.push_back(this);
}