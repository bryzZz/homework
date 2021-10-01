#include <iostream>
#include "Number.h"

//constructors
Number::Number(){
  value = 0;
}
Number::Number(int num){
  value = num;
}

//operators
Number& Number::operator+=(const Number& n){
  value += n.value;
  return *this;
}
Number& Number::operator+(const Number &n){ 
  Number res(*this); 
  return res += n; 
}

//streams
std::ostream& operator<<(std::ostream& out, const Number& n){
  out << n.value;
  return out;
}
/*
class Number {
  private:
    int value;
  public:
    Number(int i = 0): value(i) {}

    friend const Number operator+(const Number& left, const Number& right){
      return Number(left.value + right.value);
    }

    friend Number& operator+=(Number& left, const Number& right){
      left.value += right.value;
      return left;
    }

    friend const Number operator-(const Number& left, const Number& right){
      return Number(left.value - right.value);
    }

    friend Number& operator-=(Number& left, const Number& right){
      left.value -= right.value;
      return left;
    }

    friend const Number operator*(const Number& left, const Number& right){
      return Number(left.value * right.value);
    }

    friend Number& operator*=(Number& left, const Number& right){
      left.value *= right.value;
      return left;
    }

    friend const Number operator/(const Number& left, const Number& right){
      return Number(left.value / right.value);
    }

    friend Number& operator/=(Number& left, const Number& right){
      left.value /= right.value;
      return left;
    }

    friend bool operator==(const Number& left, const Number& right) {
      return left.value == right.value;
    }

    friend bool operator!=(const Number& left, const Number& right) {
      return left.value != right.value;
    }

    friend bool operator<=(const Number& left, const Number& right) {
      return left.value <= right.value;
    }

    friend bool operator>=(const Number& left, const Number& right) {
      return left.value >= right.value;
    }

    friend std::ostream& operator<<(std::ostream &out, Number i){
      out << i.getValue();
      return out;
    }

    int getValue(){
      return this->value;
    }
};
*/