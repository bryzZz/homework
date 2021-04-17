#include <iostream>
#include <vector>

using namespace std;

void vecOut(vector<int> vec){
  cout << "[";
  for(int i = 0; i < vec.size(); i++){
    if(i != vec.size() - 1){
      cout << vec[i] << ", ";
    }else{
      cout << vec[i];
    }
  }
  cout << "]" << endl;
}

void siftDown(vector<int> &vec, int start, int end){
  int root = start;

  while(true){
    int child = root * 2 + 1;
    if(child > end) break;

    if (child + 1 <= end && vec[child] < vec[child + 1]){
      child += 1;
    }

    if (vec[root] < vec[child]){
      swap(vec[root], vec[child]);
      root = child;
    }else{
      break;
    }
  }
}

vector<int> HeapSort (vector<int> vec){
  for(int start = vec.size() / 2; start > -1; start -= 1){
    siftDown(vec, start, vec.size() - 1);
  }

  vecOut(vec);

  for(int end = vec.size() - 1; end > 0; end--){
    swap(vec[end], vec[0]);
    siftDown(vec, 0, end - 1);
  }

  return vec;
}

int main() {
  vector<int> vec = {12, 11, 13, 5, 6, 7, 10, 15};
  vecOut(vec);

  vector<int> newVec = HeapSort(vec);
  vecOut(newVec);
}
