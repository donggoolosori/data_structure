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

class HashTable {
 private:
  int size;
  Node* nodeList;
  int hashFunction(string s) {
    int len = s.length();
    int hash = 0;
    for (int i = 0; i < len; i++) {
      hash += s[i];
    }
    return hash % size;
  }

 public:
  HashTable(int _size) {
    size = _size;
    nodeList = new Node[_size];
  }
  void put(string key, int value) {
    int index = hashFunction(key);
    Node* next = nodeList[index].getNext();
    Node* curr = &nodeList[index];
    while (next != NULL) {
      curr = next;
      next = next->getNext();
    }
    Node* newNode = new Node(key, value);
    curr->setNext(newNode);
  }
  Node get(string key) {
    int index = hashFunction(key);
    cout << "해시 값: " << index << '\n';
    Node* curr = nodeList[index].getNext();
    while (curr != NULL) {
      if (key == curr->getKey()) {
        return *curr;
      }
      curr = curr->getNext();
    }
    return Node();
  }
  ~HashTable() {
    for (int i = 0; i < size; i++) {
      Node* curr = nodeList[i].getNext();
      while (curr != NULL) {
        Node* temp = curr->getNext();
        delete curr;
        curr = temp;
      }
    }
    delete[] nodeList;
  }
};

int main() {
  HashTable hashTable = HashTable(100);
  hashTable.put("ac", 10);
  hashTable.put("bb", 12);
  cout << hashTable.get("ac").getValue() << '\n';
  cout << hashTable.get("bb").getValue() << '\n';

  return 0;
}