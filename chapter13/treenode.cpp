

#include <iostream>
#include <string>

class treeNode {
private:
  std::string value;
  int count;
  treeNode *left;
  treeNode *right;
  void CopyTree();
  int ReleaseTree();

public:
  treeNode();
  treeNode(const std::string &);
  treeNode(const treeNode &);
  treeNode &operator=(const treeNode &);
  ~treeNode();
};

treeNode::treeNode() : value(""), count(0), left(nullptr), right(nullptr){};

treeNode::treeNode(const std::string &s)
    : value(s), count(1), left(nullptr), right(nullptr){};

treeNode::treeNode(const treeNode &orig)
    : value(orig.value), count(orig.count), left(orig.left), right(orig.right) {
  if (left) {
    left->CopyTree();
    if (right) {
      right->CopyTree();
    }
  }
};

void treeNode::CopyTree() {
  if (left) {
    left->CopyTree();
  }
  if (right) {
    right->CopyTree();
  }
  count++;
}

int treeNode::ReleaseTree() {
  if (left) {
    left->ReleaseTree();
  }
  if (right) {
    right->ReleaseTree();
  }
  --count;
  delete this;
  return count;
}

treeNode &treeNode::operator=(const treeNode &rhs) {
  value = rhs.value;
  count = rhs.count;
  left = rhs.left;
  right = rhs.right;
  if (left) {
    left->CopyTree();
    if (right) {
      right->CopyTree();
    }
  }
  return *this;
}

treeNode::~treeNode() {
  if (count == 0) {
    delete this;
  } else {
    ReleaseTree();
  }
}