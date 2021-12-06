#include <iostream>
#include <fstream>
#include <algorithm> 
#include <vector>
#include "./modules/Node.h"

using namespace std;

void trim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

vector<int> getData(string path) {
    ifstream myfile(path);
    string line;

    if (myfile.is_open()) {
        while (myfile) {
            getline(myfile, line);

            string name;
            vector<string> names;

            for(int i = 0; i < line.length(); i++){
                if(line[i] == ' '){
                    continue;
                }

                if(line[i] == ':'){
                    names.push_back(name);
                    name = "";
                    continue;
                }

                name += line[i];
            }

            for(string name : names){
                cout << name << endl;
            }

            // vector<string> splitted = split(line, ";");

            // for(string item : splitted){
            //     vector<string> splittedItem = split(item, ":");

            //     for(string splittedString : splittedItem){
            //         trim(splittedString);
            //         cout << splittedString << "-";
            //     }
            //     cout << endl;
            // }
        }
    }

    vector<int> vec;
    return vec;
}

bool dfs(Node *v, Node *t) {
    if (v == t) {
        return true;
    }
    if (v->visited == true) {
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

int main() {

    vector<int> data = getData("./default.txt");

    // Node node1(1);
    // Node node2(2);
    // Node node3(3);
    // Node node4(4);
    // Node node5(5);
    // Node node6(6);
    // // Node *c = &a;

    // node1.connect(&node2);
    // node2.connect(&node3);
    // node2.connect(&node4);
    // node3.connect(&node5);
    // node4.connect(&node6);

    // CONNECTIONS SCHEME
    // node 1
    // │
    // node2
    // ├── node3
    // │   └── node5
    // └── node4
    //     └── node6

    // cout << "Can we get from node1 to node6? -- ";
    // cout << boolalpha << dfs(&node1, &node6) << endl;

    // cout << "Can we get from node3 to node6? -- ";
    // cout << boolalpha << dfs(&node3, &node6) << endl;

    return 0;
}