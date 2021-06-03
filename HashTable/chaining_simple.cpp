// 학번으로 학생의 이름 찾는 해쉬테이블 구현
#include <iostream>
#include <string>

using namespace std;

class Node {
 private:
  int id;
  string name;
  Node* next;

 public:
  Node() {}

  Node(int id, string name) : id(id), name(name) {}

  int getId() { return id; }

  string getName() { return name; }

  void setNext(Node* next) { this->next = next; }

  Node* getNext() { return next; }
};

class HashTable {
 private:
  int size;
  Node* hashTable;
  int hashFunction(int id) { return id % size; }

 public:
  HashTable(int size) : size(size) { hashTable = new Node[size]; }

  void put(int id, string value) {
    int key = hashFunction(id);
    Node* curr = &hashTable[key];
    Node* next = curr->getNext();

    while (next != NULL) {
      curr = next;
      next = next->getNext();
    }
    Node* newNode = new Node(id, value);
    curr->setNext(newNode);
  }

  string get(int id) {
    int key = hashFunction(id);
    Node* curr = hashTable[key].getNext();
    while (curr != NULL) {
      if (id == curr->getId()) {
        return curr->getName();
      }
      curr = curr->getNext();
    }
    return "Not Exists";
  }

  ~HashTable() {
    for (int i = 0; i < size; i++) {
      Node* curr = hashTable[i].getNext();
      while (curr != NULL) {
        Node* delNode = curr;
        curr = curr->getNext();
        delete delNode;
      }
    }
    delete[] hashTable;
  }
};

int main() {
  HashTable hashTable(10);
  hashTable.put(1234, "김동준");
  hashTable.put(1124, "김은현");
  hashTable.put(1423, "김현진");

  cout << hashTable.get(1234) << '\n';
  cout << hashTable.get(1124) << '\n';
  cout << hashTable.get(1423) << '\n';

  return 0;
}