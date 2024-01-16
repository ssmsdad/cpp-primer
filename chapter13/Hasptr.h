

#ifndef HASPTR_H
#define HASPTR_H

#include <bits/c++config.h>
#include <iostream>
#include <string>

class Hasptr {
public:
  Hasptr(const std::string &s = std::string());
  // 拷贝构造函数
  Hasptr(const Hasptr &);
  // 析构函数
  ~Hasptr();
  // 拷贝赋值运算符
  Hasptr &operator=(const Hasptr &);

private:
  std::string *ps;
  int i;
  // 引用计数
  std::size_t *use;
};

Hasptr::Hasptr(const std::string &s)
    : ps(new std::string(s)), i(0), use(new std::size_t(1)){};

//.的优先级高于*，所以可以不加括号，*orig.ps等价于*(orig.ps)，含义为指向orig.ps指向对象的指针
Hasptr::Hasptr(const Hasptr &orig)
    : ps(new std::string(*orig.ps)), i(orig.i), use(orig.use) {
  ++*use;
};

//行为像值的类
// Hasptr &Hasptr::operator=(const Hasptr &rhs) {
//   // 三种方法
//   // 1、 ps与rhs.ps指向同一个string对象，当rhs被销毁时，ps指向的对象也被销毁
//   //这种方法是绝对错误的!!!，此时ps与rhs.ps指向同一片内存空间，在执行析构函数时，会导致内存被重复释放
//   // ps = rhs.ps;
//   // 2、ps指向一个新的string对象，当rhs被销毁时，ps指向的对象不会被销毁
//   // ps = new std::string(*rhs.ps);
//   // i = rhs.i;
//   // return *this;
//   // 3、先创建对象再赋值，避免new失败时，对象被破坏
//   std::string *newps = new std::string(*rhs.ps);
//   delete ps;
//   ps = newps;
//   i = rhs.i;
//   return *this;
// }

// Hasptr::~Hasptr() { delete ps; }

//行为像指针的类
Hasptr &Hasptr::operator=(const Hasptr &rhs) {
  ++*rhs.use;
  if (--*use == 0) {
    delete ps;
    delete use;
  }
  ps = rhs.ps;
  i = rhs.i;
  use = rhs.use;
  return *this;
}

Hasptr::~Hasptr() {
  if (--*use == 0) {
    delete ps;
    delete use;
  }
}

#endif