#include <iostream>
#include <vector>
// #include "Number.h"

using namespace std;

class Number{
  private:
    int value;
    string notation;

    string splice(string str, int firstPos){
      string newString = "";
      for(int i = firstPos; i < str.length(); i++){
        newString += str[i];
      }
      return newString;
    }

    int fromOctalToDecimal(string str) {
      int res = 0;
      for (int i = 0; i < (int)str.size(); ++i) {
        res *= 8;
        res += (str[i] - '0');
      }
      return res;
    }

    int fromHexadecimalToDecimal(string str) {
      int res = 0;
      for (int i = 0; i < str.length(); i++) {
        if(str[i] == 'A'){
          res += 10;
        }else if(str[i] == 'B'){
          res += 11;
        }else if(str[i] == 'C'){
          res += 12;
        }else if(str[i] == 'D'){
          res += 13;
        }else if(str[i] == 'E'){
          res += 14;
        }else if(str[i] == 'F'){
          res += 15;
        }else{
          res += (int)str[i];
        }
      }
      return res;
    }
  
  public:
    Number(string num){
      if(num[0] == 'b'){
        notation = "binary";
        value = stoi(splice(num, 1), 0, 2);
      }else if(num[0] == '0' && num[1] == 'x'){
        value = fromHexadecimalToDecimal(splice(num, 2));
        notation = "hexadecimal";
      }else if(num[0] == '0'){
        notation = "octal";
        value = fromOctalToDecimal(num);
      }else{
        notation = "decimal";
        value = stoi(num);
      }
    }

    Number(int num){
      notation = "decimal";
      value = num;
    }
    
    Number operator+=(const Number n){
      value += n.value;
      return *this;
    }
    Number operator+(const Number n){
      Number res(*this); 
      return res += n; 
    }
    Number operator-=(const Number n){
      value -= n.value;
      return *this;
    }
    Number operator-(const Number n){
      Number res(*this); 
      return res -= n; 
    }
    Number operator++(){
      value += 1;
      return *this;
    }
    Number operator++(int){
      value += 1;
      return *this;
    }
    Number operator--(){
      value -= 1;
      return *this;
    }
    Number operator--(int){
      value -= 1;
      return *this;
    }
    Number operator*=(const Number n){
      value *= n.value;
      return *this;
    }
    Number operator*(const Number n){
      Number res(*this); 
      return res *= n; 
    }
    Number operator/=(const Number n){
      value /= n.value;
      return *this;
    }
    Number operator/(const Number n){
      Number res(*this); 
      return res /= n; 
    }

    bool operator==(const Number n){
      return value == n.value; 
    }
    bool operator!=(const Number n){
      return value != n.value; 
    }
    bool operator>(const Number n){
      return value > n.value; 
    }
    bool operator<(const Number n){
      return value < n.value; 
    }
    bool operator>=(const Number n){
      return value >= n.value; 
    }
    bool operator<=(const Number n){
      return value <= n.value; 
    }

    operator int(){
      return value;
    }

    Number pow(int power){
      if(power == 1){
        return *this;
      }else if(power == 0){
        return Number(1);
      }else{
        return (*this * pow(power-1));
      }
    }

    friend ostream& operator<<(ostream& out, const Number& n){
      out << n.value;
      return out;
    }
};

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