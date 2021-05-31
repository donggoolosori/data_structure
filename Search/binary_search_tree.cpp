#include <iostream>
#include <string>

using namespace std;

class Node {
 private:
  int key, data;
  Node *left, *right;

 public:
  Node(int key, int data) : key(key), data(data) {}
  int getKey() { return key; }
  int getData() { return data; }
  void setLeft(Node* newNode) { left = newNode; }
  Node* getLeft() { return left; }
  void setRight(Node* newNode) { right = newNode; }
  Node* getRight() { return right; }
};

class Tree {
 private:
  Node* root;

 public:
  Tree() : root(NULL) {}
  void insert(int key, int data) {
    Node* newNode = new Node(key, data);
    if (root == NULL) {
      root = newNode;
      return;
    }
    Node* curr = root;
    Node* parent = NULL;
    while (curr != NULL) {
      parent = curr;
      if (curr->getKey() > key)
        curr = curr->getLeft();
      else
        curr = curr->getRight();
    }

    if (parent->getKey() < key)
      parent->setRight(newNode);
    else
      parent->setLeft(newNode);
  }

  int get(int key) {
    Node* curr = root;
    while (curr != NULL) {
      if (curr->getKey() == key) return curr->getData();
      if (key < curr->getKey()) {
        curr = curr->getLeft();
      } else {
        curr = curr->getRight();
      }
    }
    return -1;
  }
  void clear(Node* curr) {
    if (curr == NULL) return;
    clear(curr->getLeft());
    clear(curr->getRight());
    delete curr;
  }
  ~Tree() { clear(root); }
};

int main() {
  Tree tree;
  tree.insert(2001, 1);
  tree.insert(2002, 2);
  tree.insert(2003, 3);
  tree.insert(2004, 4);
  cout << tree.get(2004) << '\n';
  return 0;
}