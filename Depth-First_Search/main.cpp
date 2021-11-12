#include <iostream>
#include "Node.h"
#include <set>

using namespace std;

int main()
{
    Node a(1);
    Node b(1);

    a.connect(&b);

    auto it = a.connections.begin();

    cout << *it->value; // 1
    // it++;
    // cout << *it; // 2

    return 0;
}