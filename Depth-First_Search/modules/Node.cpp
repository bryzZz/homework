#include "Node.h"

Node::Node(int value)
{
    this->value = value;
    // this->visited = false;
}

void Node::connect(Node *node, int weight){
    Connection connection = {node, weight};
    
    this->connections.push_back(connection);
}