#include <iostream>
#include <string>

using namespace std;

class Node {
 private:
  string key;
  int value;
  Node* next;

 public:
  Node() : key(""), value(0), next(NULL){};
  Node(string _key, int _value) {
    key = _key;
    value = _value;
    next = NULL;
  }
  Node* getNext() { return next; }
  void setNext(Node* nextNode) { next = nextNode; }
  string getKey() { return key; }
  int getValue() { return value; }
};

int main() { return 0; }