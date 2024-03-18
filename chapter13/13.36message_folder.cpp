

#include <iostream>
#include <memory>
#include <set>
#include <string>


// 了解三五法则，搞懂这一页的代码就可以了
// Message是一个类，表示邮件，一个邮件可以保存在多个Folder中
// Folder是一个类，表示邮件的文件夹，一个文件夹中可以保存多个邮件

class Folder;
class Message {
  friend class Folder;
  friend void swap(Message &, Message &);

public:
  Message(const std::string &str = "") : contents(str) {}
  // 拷贝构造函数
  Message(const Message &);
  // 拷贝赋值运算符
  Message &operator=(const Message &);
  // 析构函数
  ~Message();
  // 移动构造函数s
  Message(Message &&);
  // 移动赋值运算符
  Message &operator=(Message &&);
  void save(Folder &);
  void remove(Folder &);
  void debug_print();
  void move_Folders(Message *m);

private:
  std::string contents;
  std::set<Folder *> folders; // 保存该Message的Folder
  void add_to_Folder(const Message &);
  void rem_from_Folder();
};

void swap(Message &lhs, Message &rhs);

class Folder {
public:
  Folder() = default;
  Folder(const Folder &);
  Folder &operator=(const Folder &);
  ~Folder();
  void addMsg(Message *m);
  void remMsg(Message *m);
  void debug_print();

private:
  std::set<Message *> messages; // 保存该Folder的Message
  void add_to_Message(const Folder &);
  void rem_from_Message();
};

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMsg(this);
}

void Message::add_to_Folder(const Message &m) {
  for (auto f : m.folders) {
    f->addMsg(this);
  }
}

void Message::rem_from_Folder() {
  for (auto f : folders) {
    f->remMsg(this);
  }
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_Folder(m);
}

Message::~Message() { rem_from_Folder(); }

Message &Message::operator=(const Message &rhs) {
  rem_from_Folder();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folder(rhs);
  return *this;
}

void Message::debug_print() { std::cout << contents << std::endl; }


void Message::move_Folders(Message *m) {
  folders = std::move(m->folders);
  for (auto f : folders) {
    f->remMsg(m);
    f->addMsg(this);
  }
  m->folders.clear();
}

Message::Message(Message &&m) : contents(std::move(m.contents)) {
  move_Folders(&m);
}

Message &Message::operator=(Message &&rhs) {
  if (this != &rhs) {
    rem_from_Folder();
    contents = std::move(rhs.contents);
    move_Folders(&rhs);
  }
  return *this;
}


void swap(Message &lhs, Message &rhs) {
  using std::swap;
  for (auto f : lhs.folders) {
    f->remMsg(&lhs);
  }
  for (auto f : rhs.folders) {
    f->remMsg(&rhs);
  }
  swap(lhs.folders, rhs.folders);
  swap(lhs.contents, rhs.contents);
  for (auto f : lhs.folders) {
    f->addMsg(&lhs);
  }
  for (auto f : rhs.folders) {
    f->addMsg(&rhs);
  }
}

void Folder::addMsg(Message *m) {
  messages.insert(m);
  m->folders.insert(this);
}

void Folder::remMsg(Message *m) {
  messages.erase(m);
  m->folders.erase(this);
}

void Folder::add_to_Message(const Folder &f) {
  for (auto m : f.messages) {
    m->folders.insert(this);
  }
}

void Folder::rem_from_Message() {
  for (auto m : messages) {
    m->folders.erase(this);
  }
}

Folder::Folder(const Folder &f) : messages(f.messages) { add_to_Message(f); }

Folder::~Folder() { rem_from_Message(); }

Folder &Folder::operator=(const Folder &rhs) {
  rem_from_Message();
  messages = rhs.messages;
  add_to_Message(rhs);
  return *this;
}

void Folder::debug_print() {
  for (auto m : messages) {
    m->debug_print();
  }
}




int main() {
  Message firstMail("hello");
  Message signInMail("welcome to cppprimer");
  Folder mailBox;

  firstMail.debug_print(); 
  firstMail.save(mailBox); 
  mailBox.debug_print();   
  std::cout << std::endl;
  signInMail.debug_print(); 
  signInMail.save(mailBox); 
  mailBox.debug_print();    
}