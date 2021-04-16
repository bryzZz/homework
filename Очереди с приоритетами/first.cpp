#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> split(const string &s, char delim) {
  vector<int> elems;
  stringstream ss;
  ss.str(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(stoi(item));
  }
  return elems;
}

bool is_complete(string H){
  vector<int> elems = split(H, ',');
  for(auto e : elems){
    cout << e << ", ";
  }
  cout << endl;

  for(int i = 0; i < (elems.size() - 2) / 2; i++){
    if(!(elems[i] <= elems[2 * i + 1])) return false;
    if(!(elems[i] <= elems[2 * i + 2])) return false;
  }

  return true;
}

int main() {
  string s = "1, 4, 2, 3, 4, 5, 6";
  cout << boolalpha << is_complete(s);
}