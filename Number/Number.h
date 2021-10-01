#ifndef Number_H
#define Number_H

class Number{
  private:
    int value;

  public:
    Number();
    Number(int num);
    
    Number& operator+=(const Number& n);
    Number& operator+(const Number& n);

    friend std::ostream& operator<<(std::ostream& out, const Number& n);
};

#endif