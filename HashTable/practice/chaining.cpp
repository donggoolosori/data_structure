// 학번으로 학생정보를 찾는 해쉬 테이블
#include <iostream>
#include <string>

using namespace std;

class Student {
 private:
  int id;
  string name, major, email;

 public:
  Student() : id(0), name(""), major(""), email("") {}
  Student(int id, string name, string major, string email)
      : id(id), name(name), major(major), email(email) {}
  int getId() { return id; }
  void showInfo() {
    cout << "이름: " << name << '\n'
         << "전공: " << major << '\n'
         << "email: " << email << '\n'
         << '\n';
  }
};

class Node {
 private:
  int key;
  Student value;
  Node* next;

 public:
  Node() : key(0), value(), next(NULL){};
  Node(int key, Student value) : key(key), value(value), next(NULL) {}
  Node* getNext() { return next; }
  void setNext(Node* next) { this->next = next; }
  int getKey() { return key; }
  Student getValue() { return value; }
};

class HashTable {
 private:
  int size;
  Node* nodeList;
  int hashFunction(int key) { return key % 100; }

 public:
  HashTable(int size) {
    this->size = size;
    nodeList = new Node[size];
  }
  void put(int key, Student value) {
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
  Node get(int key) {
    int index = hashFunction(key);
    cout << "- "
         << "해시값: " << index << " -" << '\n';
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
  // 학생정보
  Student std1(95, "김동준", "신소재공학부", "kdj6551@naver.com"),
      std2(195, "김은현", "전기공학부", "dmsgus@naver.com"),
      std3(200, "김현진", "기계공학부", "guswls@naver.com");
  // Hash Table 생성
  HashTable hash_table(100);

  // 학번을 key로 사용하여 hash table에 put
  hash_table.put(std1.getId(), std1);
  hash_table.put(std2.getId(), std2);
  hash_table.put(std3.getId(), std3);

  // hash table에서 학번을 key로 학생정보 탐색
  hash_table.get(std1.getId()).getValue().showInfo();
  hash_table.get(std2.getId()).getValue().showInfo();
  hash_table.get(std3.getId()).getValue().showInfo();

  return 0;
}