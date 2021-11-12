#include "Node.h"
#include <set>

Node::Node(int value)
{
    this->value = value;
}

void Node::connect(Node *node)
{
    this->connections.insert(node);
    node.connect(this);
}