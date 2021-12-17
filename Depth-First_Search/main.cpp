#include <iostream>
#include <algorithm>
#include <vector>
#include "./modules/Node.h"

using namespace std;

bool dfs(Node *v, Node *t, vector<Node*> *visitedVec = nullptr) {
    if (v == t) {
        return true;
    }

    if(visitedVec == nullptr){
        vector<Node*> vec = {};
        visitedVec = &vec;
    }

    if(find(visitedVec->begin(), visitedVec->end(), v) != visitedVec->end()) {
        return false;
    }

    visitedVec->push_back(v);

    for (int i = 0; i < v->connections.size(); i++) {
        // if(find(visitedVec->begin(), visitedVec->end(), v->connections[i].node) == visitedVec->end()){
            bool reached = dfs(v->connections[i].node, t, visitedVec);

            if (reached == true) {
                return true;
            }
        // }
        // if (v->connections[i].node->visited == false) {
        //     bool reached = dfs(v->connections[i].node, t, visitedVec);

        //     if (reached == true) {
        //         return true;
        //     }
        // }
    }

    return false;
}

int main() {
    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    Node node5(5);
    Node node6(6);
    Node node7(7);
    Node node8(8);
    Node node9(9);
    Node node10(10);

    node1.connect(&node2, 1);
    node1.connect(&node3, 2);
    node2.connect(&node4, 3);
    node3.connect(&node1, 2);
    node3.connect(&node5, 4);
    node3.connect(&node6, 5);
    node5.connect(&node3, 4);
    node5.connect(&node7, 7);
    node5.connect(&node10, 8);
    node6.connect(&node9, 9);
    node7.connect(&node5, 7);
    node7.connect(&node8, 11);
    node8.connect(&node7, 11);
    node9.connect(&node6, 9);

    cout << "Can we get from node1 to node6? -- ";
    cout << boolalpha << dfs(&node1, &node6) << endl;

    cout << "Can we get from node1 to node5? -- ";
    cout << boolalpha << dfs(&node1, &node5) << endl;

    cout << "Can we get from node1 to node10 -- ";
    cout << boolalpha << dfs(&node1, &node10) << endl;

    cout << "Can we get from node1 to node9 -- ";
    cout << boolalpha << dfs(&node1, &node9) << endl;

    cout << "Can we get from node2 to node1 -- ";
    cout << boolalpha << dfs(&node2, &node1) << endl;

    return 0;
}