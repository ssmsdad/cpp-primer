
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
private:
  std::string name;
  std::string address;

public:
  Person() = default;
  Person(const std::string &n, const std::string &a) : name(n), address(a){};
  Person(std::istream &is) { read(is, *this); };
  std::string getName() const { return this->name; }
  std::string getAddress() const { return this->address; }
  std::istream &read(std::istream &, Person &);
  std::ostream &print(std::ostream &, const Person &);
};

std::istream &Person::read(std::istream &is, Person &person) {
  is >> person.name >> person.address;
  return is;
}

std::ostream &Person::print(std::ostream &os, const Person &person) {
  os << person.name << " " << person.address;
  return os;
}
#endif
