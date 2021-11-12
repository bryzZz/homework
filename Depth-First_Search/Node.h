// #include <string>
#include <vector>

using namespace std;

class Node
{

public:
    int value;
    bool visited;
    vector<Node *> connections;

    Node(int value);

    void connect(Node *node);

    // Number(string num);
    // Number(int num);

    // Number operator+=(const Number n);
    // Number operator+(const Number n);
    // Number operator-=(const Number n);
    // Number operator-(const Number n);
    // Number operator*=(const Number n);
    // Number operator*(const Number n);
    // Number operator/=(const Number n);
    // Number operator/(const Number n);
    // Number operator++();
    // Number operator--();
    // Number operator++(int);
    // Number operator--(int);

    // bool operator==(const Number n);
    // bool operator!=(const Number n);
    // bool operator>(const Number n);
    // bool operator<(const Number n);
    // bool operator>=(const Number n);
    // bool operator<=(const Number n);
};