#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
  // Числа Армстронга
  for(int a = 1; a < 32000; a++){
    int temp = 0;
    string aStr = to_string(a);
    for(int i = 0; i < aStr.length(); i++){
      temp += pow(((int)aStr[i] - '0'), aStr.length());
    }
    if(temp == a){
      cout << temp << ", ";
    }
  }
}