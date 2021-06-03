// 현재 segmentaion fault
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
  void setKey(int key) { this->key = key; }
  int getData() { return data; }
  void setData(int data) { this->data = data; }
  void setLeft(Node* newNode) { left = newNode; }
  Node* getLeft() { return left; }
  void setRight(Node* newNode) { right = newNode; }
  Node* getRight() { return right; }
  ~Node() { delete this; }
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

  void erase(int key) {
    if (root == NULL) return;
    Node* curr = root;
    Node* parent = NULL;
    while (curr != NULL) {
      parent = curr;
      if (curr->getKey() == key) break;
      if (curr->getKey() < key) {
        curr = curr->getRight();
      } else {
        curr = curr->getLeft();
      }
    }

    // 삭제 노드가 단말노드일 경우
    if (curr->getLeft() == NULL && curr->getRight() == NULL) {
      if (parent->getLeft() == curr) {
        parent->setLeft(NULL);
      } else {
        parent->setRight(NULL);
      }
      delete curr;
    }
    // 오른쪽 노드만 갖는경우
    else if (curr->getLeft() == NULL) {
      if (parent->getLeft() == curr) {
        parent->setLeft(curr->getRight());
        delete curr;
      } else {
        parent->setRight(curr->getRight());
        delete curr;
      }
      // 왼쪽 노드만 갖는경우
    } else if (curr->getRight() == NULL) {
      if (parent->getLeft() == curr) {
        parent->setLeft(curr->getLeft());
        delete curr;
      } else {
        parent->setRight(curr->getLeft());
        delete curr;
      }
    } else {
      Node* minParent = curr;
      Node* minNode = curr->getRight();
      while (minNode->getLeft() != NULL) {
        minParent = minNode;
        minNode = minNode->getLeft();
      }
      curr->setData(minNode->getData());
      curr->setKey(minNode->getKey());
      if (minParent->getLeft() == minNode) {
        minParent->setLeft(minNode->getRight());
      } else {
        minParent->setRight(minNode->getRight());
      }
      delete minNode;
    }
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
  void clear(Node* root) {
    if (root == NULL) return;

    clear(root->getLeft());
    clear(root->getRight());
    delete root;
  }
  ~Tree() { clear(root); }
};

int main() {
  Tree* tree = new Tree();

  tree->insert(2001, 1);
  tree->insert(2002, 2);
  tree->insert(2003, 3);
  tree->insert(2004, 4);

  tree->erase(2004);

  cout << tree->get(2004) << '\n';

  delete tree;
  return 0;
}