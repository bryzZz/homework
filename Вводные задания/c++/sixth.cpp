#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> generateList(int n, int m){
  vector<vector<int>> arr;

  for(int i = 0; i < n; i++){
    vector<int> tempArr;
    for(int j = 0; j < m; j++){
      tempArr.push_back(10 + rand() % 40);
    }
    arr.push_back(tempArr);
  }

  return arr;
}

int findBiggest(vector<vector<int>> &arr){
  int index = 0;
  int biggestSum = arr[0][0];
  for(int j = 1; j < arr[0].size(); j++){
    biggestSum += arr[0][j];
  }
  for(int i = 1; i < arr.size(); i++){
    int secondSum = 0;
    for(int j = 0; j < arr[i].size(); j++){
      secondSum += arr[i][j];
    }
    if(secondSum > biggestSum){
      biggestSum = secondSum;
      index = i;
    }
  }
  return index;
}

void outPut(vector<vector<int>> &arr){
  for(int i = 0; i < arr.size(); i++){
    for(int j = 0; j < arr[i].size(); j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  srand(time(0));
  int n, m;
  cout << "Enter n: ";
  cin >> n;
  cout << "Enter m: ";
  cin >> m;

  vector<vector<int>> arr = generateList(n, m);
  outPut(arr);
  cout << endl;

  int biggestIndex = findBiggest(arr);

  cout << biggestIndex+1 << ": [";
  for(int i = 0; i < arr[biggestIndex].size(); i++){
    if(i != arr[biggestIndex].size()-1){
      cout << arr[biggestIndex][i] << ", ";
    }else{
      cout << arr[biggestIndex][i] << "]";
    }
  }
}
