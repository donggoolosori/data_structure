// 연결리스트 구현
#include <iostream>

using namespace std;

class Node {
 private:
  int data;
  Node *next;

 public:
  Node(int data) : data(data), next(NULL){};
  int getData() { return data; }
  void setNext(Node *next) { this->next = next; }
};

class List {
 private:
  int size;
  Node *head, *tail, *curr;

 public:
  List() : size(0), head(NULL), tail(NULL), curr(NULL) {}
  // list에 저장된 데이터 수 반환
  int size() { return size; }
  // 삽입
  void insert(int data) {
    size++;
    Node *newNode = new Node(data);
    if (head == NULL) {
      head = newNode;
    } else {
      tail->setNext(newNode);
    }
    tail = newNode;
  }
  // 가장 앞의 데이터 반환
  int front() {
    if (head == NULL) {
      return -1;
    } else {
      return head->getData();
    }
  }
  // 가장 뒤 데이터 반환
};

int main() { return 0; }