

#include <iostream>
#include <set>
#include <string>

class Folder;
class Message {
  friend class Folder;
  friend void swap(Message &, Message &);

public:
  Message(const std::string &str = "") : contents(str) {}
  Message(const Message &);
  Message &operator=(const Message &);
  ~Message();
  void save(Folder &);
  void remove(Folder &);
  void debug_print();

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

  firstMail.debug_print(); // print: "hello"
  firstMail.save(mailBox); // send to mailBox
  mailBox.debug_print();   // print: "hello"
  std::cout << std::endl;
  signInMail.debug_print(); // print "welcome to cppprimer"
  signInMail.save(mailBox); // send to mailBox
  mailBox.debug_print();    // print "welcome to cppprimer hello"
}