#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int devsSum(int num){
  int s = 0;
  for(int i = 1; i < num; i++){
    if(num % i == 0){
      s += i;
    }
  }
  return s;
}
vector<int> findBetrothed(int limit){
  vector<int> myVector;
  for(int i = 1; i < limit; i++){
    if(find(myVector.begin(), myVector.end(), i) == myVector.end()){
      int temp = devsSum(i)-1;
      if(i == devsSum(temp)-1 && i != temp-1){
        myVector.push_back(i);
        myVector.push_back(temp);
      }
    }
  }
  return myVector;
}
void pairedOutput(const vector<int>& vec){
  for(int i = 0; i < vec.size(); i += 2){
    cout << vec[i] << ", " << vec[i+1] << endl;
  }
}
int main() {
  pairedOutput(findBetrothed(10000));
}