#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

//split function
vector<string> split(const string &s, char delim) {
  vector<string> elems;
  stringstream ss;
  ss.str(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

void recursion(vector<vector<int>> dots, int dot, set<int> &visited){
  visited.insert(dot);

  for(int i = 0; i < dots.size(); i++){
    if(visited.find(i) != visited.end()) continue;

    float dist = sqrt(pow((dots[i][0] - dots[dot][0]), 2) + pow((dots[i][1] - dots[dot][1]), 2));
    if(dist <= 1){
      recursion(dots, i, visited);
    }
  }
}

int getColorsCount(vector<vector<int>> &dots){
  set<int> visited;

  int colorCount = 0;

  while(dots.size() != 0){
    recursion(dots, 0, visited);

    vector<vector<int>> newArr;
    for(int i = 0; i < dots.size(); i++){
      if(visited.find(i) != visited.end()) continue;
      newArr.push_back(dots[i]);
    }
    dots = newArr;

    colorCount++;
    visited.clear();
  }

  return colorCount;
}

int main() {

  //main vector
  vector<vector<int>> dots;
  
  //get data from file
  ifstream inputF;
	inputF.open("input.txt");
  string str;
	while (getline(inputF, str)) {
		vector<string> strInArr = split(str, ' ');
    vector<int> innerVector;
    innerVector.push_back(stoi(strInArr[0]));
    innerVector.push_back(stoi(strInArr[1]));
    dots.push_back(innerVector);
	}
  inputF.close();

  cout << getColorsCount(dots);
}