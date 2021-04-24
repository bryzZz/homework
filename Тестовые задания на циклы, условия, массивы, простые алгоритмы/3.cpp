#include <iostream>
#include <cmath>

using namespace std;

string toTernaryString(int num){
  string result;
  do{
    result = (to_string(num % 3)) + result;
    num = num / 3;
  }
  while (num > 0);

  return result;
}

int toDecimal(string num){
  int result = 0;
  int len = num.length() - 1;
  for (int i = 0; i < num.length(); i++){
    result += (int(num[i]) - 48) * pow(3, len);
    len--;
  }
  return result;
}

int main() {
  int num;
  
  cout << "enter number: ";
  cin >> num;

  string ternaryStr = toTernaryString(num);

  string ONEMORESTRING;
  for(int i = 0; i < ternaryStr.length(); i++){
    ONEMORESTRING += ternaryStr[i];
    ONEMORESTRING += ternaryStr[i];
  }

  int result = toDecimal(ONEMORESTRING);

  cout << result;
}