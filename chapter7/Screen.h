#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>

//屏幕类，包含窗口大小，光标位置，屏幕内容
class Screen {
  //声明Window_mgr类为Screen的友元类，可以访问其私有成员
  friend class Window_mgr;
  // friend void Window_mgr::clear(ScreenIndex);
public:
  typedef std::string::size_type pos;
  //构造函数
  Screen() = default;
  Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  char get() const;
  char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  Screen &set(char);
  Screen &set(pos, pos, char);
  Screen &display(std::ostream &os);
  const Screen &display(std::ostream &os) const;
  pos size() const;

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  void do_displays(std::ostream &os) const { os << contents; }
};

// windows管理类，包含一个Screen类的vector
class Window_mgr {
public:
  using ScreenIndex = std::vector<Screen>::size_type;
  void clear(ScreenIndex);

private:
  std::vector<Screen> screen{Screen(24, 80, ' ')}; //默认初始化一个Screen对象
};
inline char Screen::get() const { return contents[cursor]; }

inline char Screen::get(pos ht, pos wd) const {
  pos row = ht * width;
  return contents[row + wd];
}

inline Screen &Screen::move(pos ht, pos wd) {
  pos row = ht * width;
  cursor = row + wd;
  return *this;
}

inline Screen &Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos ht, pos wd, char c) {
  contents[ht * width + wd] = c;
  return *this;
}

inline Screen &Screen::display(std::ostream &os) {
  do_displays(os);
  return *this;
}

inline const Screen &Screen::display(std::ostream &os) const {
  do_displays(os);
  return *this;
}

void Window_mgr::clear(ScreenIndex i) {
  Screen &s = screen[i];
  s.contents = std::string(s.height * s.width, ' ');
}

//遇到类名之后，定义的剩余部分都在类的作用域之内，这里的剩余部分包括参数列表和函数体，但是返回类型不在类的作用域之内，所以返回类型需要是Screen::pos，而不是pos
Screen::pos Screen::size() const { return height * width; }
#endif