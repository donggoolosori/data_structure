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
  Node *getNext() { return next; }
  void setNext(Node *next) { this->next = next; }
};

class List {
 private:
  int list_size;
  Node *head, *tail;

 public:
  List() : list_size(0), head(NULL), tail(NULL) {}
  // list에 저장된 데이터 수 반환
  int size() { return list_size; }
  // 삽입
  void insert(int data) {
    list_size++;
    Node *newNode = new Node(data);
    if (head == NULL) {
      head = newNode;
    } else {
      tail->setNext(newNode);
    }
    tail = newNode;
  }
  // 특정 인덱스에 삽입
  void insert(int data, int index) {
    if (index > list_size) {
      cout << "삽입가능 범위가 아닙니다\n";
      return;
    }
    list_size++;
    Node *newNode = new Node(data);
    Node *prev = NULL;
    Node *curr = head;
    int cnt = 0;
    while (true) {
      if (cnt == index) {
        if (cnt == 0) {
          newNode->setNext(head);
          head = newNode;
        } else if (cnt == list_size - 1) {
          insert(data);
          list_size--;  // insert 함수에서 중복으로 size 증가
        } else {
          prev->setNext(newNode);
          newNode->setNext(curr);
        }
        return;
      }
      prev = curr;
      curr = curr->getNext();
      cnt++;
    }
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
  int back() {
    if (tail == NULL) {
      return -1;
    } else {
      return tail->getData();
    }
  }
  ~List() {
    Node *next = head->getNext();
    Node *curr = head;

    while (curr != NULL) {
      delete curr;
      curr = next;
      if (next != NULL) next = next->getNext();
    }
  }
};

int main() {
  List list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4, 0);

  cout << list.size() << '\n';
  cout << list.front() << '\n';
  cout << list.back() << '\n';

  return 0;
}