
#include <iostream>

class numbered {
private:
  static int seq;

public:
  int mynum;

public:
  numbered();
  numbered(const numbered &);
};

int numbered::seq = 0;
//对s不加引用，会导致在调用f时，调用拷贝构造函数，将实参拷贝给形参，最终输出为3,4,5,而不是0,1,2
//!!!!
// void f(numbered s) { std::cout << s.mynum << std::endl; }
void f(numbered &s) { std::cout << s.mynum << std::endl; }

numbered::numbered() {
  mynum = seq++;
  std::cout << "调用构造函数" << std::endl;
}

numbered::numbered(const numbered &orig) {
  mynum = seq++;
  std::cout << "调用拷贝构造函数" << std::endl;
}

int main() {
  numbered a, b = a, c = b;
  f(a);
  f(b);
  f(c);
  return 0;
}