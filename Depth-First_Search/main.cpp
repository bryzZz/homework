#include <iostream>
#include "Node.h"
#include <vector>

using namespace std;

bool dfs(Node *v, Node *t)
{
    if (v == t)
    {
        return true;
    }
    if (v->visited == true)
    {
        return false;
    }

    v->visited = true;

    for (int i = 0; i < v->connections.size(); i++)
    {
        if (v->connections[i]->visited == false)
        {
            bool reached = dfs(v->connections[i], t);

            if (reached == true)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    Node node5(5);
    Node node6(6);
    // Node *c = &a;

    node1.connect(&node2);
    node2.connect(&node3);
    node2.connect(&node4);
    node3.connect(&node5);
    node4.connect(&node6);

    // CONNECTIONS SCHEME
    // node 1
    // │
    // node2
    // ├── node3
    // │   └── node5
    // └── node4
    //     └── node6

    cout << boolalpha << dfs(&node1, &node6) << endl;

    cout << boolalpha << dfs(&node3, &node6) << endl;

    return 0;
}