#include <iostream>
#include <vector>
#include "Number.h"

using namespace std;

vector<Number> insertionSort(vector<Number> vec){
  for(int i = 1; i < vec.size(); i++){
    for(int j = i; j > 0 && vec[j-1] > vec[j]; j--){
			swap(vec[j-1], vec[j]);
    }
  }

  return vec;
}

void coutVector(vector<Number> vec){
  cout << "[ ";
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << ", ";
  }
  cout << "]\n";
}

int main() {
  Number dec("10");
  Number bin("b1010"); // 10
  Number oct("016"); // 14
  Number hex("0xE"); // 14

  cout << "Вывод всегда в десятичной системе\n";
  cout << dec << " " << bin << " " << oct << " " << hex << "\n";

  cout << "Чтобы вывести в другой системе нужно изменить вывод\n";
  cout << std::hex << hex << "\n";

  cout << "Умножение\n";
  cout << std::dec << "dec(10) * hex(14) = " << (dec * hex) << "\n";

  cout << "Остальные действия можете посмотреть сами\n";

  cout << "Сортировка вставками\n";

  vector<Number> vec({Number("5"), Number("4"), Number("3"), Number("2"), Number("1")});

  coutVector(vec);

  vector<Number> sortedVec = insertionSort(vec);

  coutVector(sortedVec);

  return 0;
}