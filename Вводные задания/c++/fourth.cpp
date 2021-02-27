#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  string inputStr;
  cout << "Enter string: ";
  cin >> inputStr;

  vector<char> arr;
  for(int i = 0; i < inputStr.length(); i++){
    arr.push_back(inputStr[i]);
  }

  int numGC = 0;
  for(int i = 0; i < arr.size(); i++){
    if(arr[i] == 'g' || arr[i] == 'c'){
      numGC++;
    }
  }

  float result = float(numGC) / float(inputStr.length()) * 100;
  cout << result; 
}
