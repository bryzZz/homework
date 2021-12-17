#include <vector>

using namespace std;

class Node {
    private:
        struct Connection {
            Node *node;
            int weight;
        };

    public:
        int value;
        // bool visited;
        vector<Connection> connections;

        Node(int value);

        void connect(Node *node, int weight);
};