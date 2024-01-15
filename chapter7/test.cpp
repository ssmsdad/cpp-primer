#include <iostream>
#include <string>
using namespace std;

// 该类型没有显式定义默认构造函数，编译器也不会为它合成一个
class NoDefault {
public:
  NoDefault(int i) : val(i){};
  NoDefault(int i, int j) : val(i), val2(j){};
  int val;
  int val2;
  // 静态成员的类内声明
  static constexpr int period = 10;
};
// 静态成员的类内初始化
constexpr int NoDefault::period;

class C {
public:
  NoDefault nd;
  //两种初始化方式
  NoDefault nd2{1, 2};
  NoDefault nd3 = NoDefault(3, 4);
  NoDefault nd4 = {3, 4};
  // 必须显式调用 NoDefault 的带参构造函数初始化 nd
  //如果某个构造函数包含若干形参，但是同时为这些形参都提供了默认实参，则该构造函数也具备默认构造函数的功能
  C(int i = 0) : nd(i) {}
  //   C(int i = 0) : nd(nd{i}) {}
};

int main() {
  C c; // 使用了类型 C 的默认构造函数
  cout << c.nd.val << endl;
  cout << c.nd2.val << endl;
  cout << c.nd2.val2 << endl;
  cout << c.nd3.val << endl;
  cout << c.nd3.val2 << endl;
  cout << c.nd4.val << endl;
  cout << c.nd4.val2 << endl;
  return 0;
}