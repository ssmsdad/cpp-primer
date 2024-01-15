

#ifndef HASPTR_H
#define HASPTR_H

#include <iostream>
#include <string>

class Hasptr {
public:
  Hasptr(const std::string &s) : ps(new std::string(s)), i(0){};
  // 拷贝构造函数
  Hasptr(const Hasptr &);
  // 析构函数
  ~Hasptr();
  // 拷贝赋值运算符
  Hasptr &operator=(const Hasptr &);

private:
  std::string *ps;
  int i;
};

Hasptr::Hasptr(const Hasptr &orig) : ps(new std::string(*orig.ps)), i(orig.i){};
Hasptr &Hasptr::operator=(const Hasptr &rhs) {
  // 三种方法
  // 1、 ps与rhs.ps指向同一个string对象，当rhs被销毁时，ps指向的对象也被销毁
  //这种方法是绝对错误的!!!，此时ps与rhs.ps指向同一片内存空间，在执行析构函数时，会导致内存被重复释放
  // ps = rhs.ps;
  // 2、ps指向一个新的string对象，当rhs被销毁时，ps指向的对象不会被销毁
  // ps = new std::string(*rhs.ps);
  // i = rhs.i;
  // return *this;
  // 3、先创建对象再赋值，避免new失败时，对象被破坏
  std::string *newps = new std::string(*rhs.ps);
  delete ps;
  ps = newps;
  i = rhs.i;
  return *this;
}

Hasptr::~Hasptr() { delete ps; }

#endif