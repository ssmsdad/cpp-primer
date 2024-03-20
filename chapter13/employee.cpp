

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class employee {
private:
  std::string name;
  int id;
  static int unique_id;

public:
  employee();
  employee(const std::string &);
  employee(const employee &);
  employee &operator=(const employee &);
  ~employee() = default;
};

employee::employee() : id(unique_id++) {}

employee::employee(const std::string &s) : name(s), id(unique_id++) {}

employee::employee(const employee &orgin) : name(orgin.name), id(unique_id++) {}

employee &employee::operator=(const employee &rhs) {
  name = rhs.name;
  id = unique_id++;
  return *this;
}

#endif