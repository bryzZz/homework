// #include <string>
// #include <vector>
#include <set>

using namespace std;

class Node
{
private:
    // int value;
    // string notation;
    // string splice(string str, int firstPos);
    // int fromOctalToDecimal(string str);
    // int fromHexadecimalToDecimal(string str);

public:
    int value;
    set<Node *> connections;
    // Node *connections;

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

    // operator int();

    // Number pow(int power);

    // friend std::ostream& operator<<(std::ostream& out, const Number& n);
};