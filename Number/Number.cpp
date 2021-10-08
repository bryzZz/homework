#include "Number.h"

//constructors
Number::Number(string num){
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
Number::Number(int num){
  notation = "decimal";
  value = num;
}

Number::string splice(string str, int firstPos){
  string newString = "";
  for(int i = firstPos; i < str.length(); i++){
    newString += str[i];
  }
  return newString;
}
Number::int fromOctalToDecimal(string str){
  int res = 0;
  for (int i = 0; i < (int)str.size(); ++i) {
    res *= 8;
    res += (str[i] - '0');
  }
  return res;
}
Number::int fromHexadecimalToDecimal(string str){
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

//operators
Number Number::operator+=(const Number n){
  value += n.value;
  return *this;
}
Number Number::operator+(const Number n){ 
  Number res(*this); 
  return res += n; 
}
Number Number::operator-=(const Number n){
  value -= n.value;
  return *this;
}
Number Number::operator-(const Number n){ 
  Number res(*this); 
  return res -= n; 
}
Number Number::operator*=(const Number n){
  value *= n.value;
  return *this;
}
Number Number::operator*(const Number n){ 
  Number res(*this); 
  return res *= n; 
}
Number Number::operator/=(const Number n){
  value /= n.value;
  return *this;
}
Number Number::operator/(const Number n){ 
  Number res(*this); 
  return res /= n; 
}
Number Number::operator++(){ 
  value += 1;
  return *this;
}
Number Number::operator--(){ 
  value -= 1;
  return *this;
}
Number Number::operator++(int){ 
  value += 1;
  return *this;
}
Number Number::operator--(int){ 
  value -= 1;
  return *this;
}

Number bool operator==(const Number n){
  return value == n.value; 
}
Number bool operator!=(const Number n){
  return value != n.value; 
}
Number bool operator>(const Number n){
  return value > n.value; 
}
Number bool operator<(const Number n){
  return value < n.value; 
}
Number bool operator>=(const Number n){
  return value >= n.value; 
}
Number bool operator<=(const Number n){
  return value <= n.value; 
}

Number operator int(){
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

//streams
std::ostream& operator<<(std::ostream& out, const Number& n){
  out << n.value;
  return out;
}