#include <iostream>

using namespace std;

template <typename T>
class Node {
 private:
  T data;
  Node<T>* next;

 public:
  Node(T data) {
    this->data = data;
    next = NULL;
  }
  T getData() { return data; }
  Node<T>* getNext() { return next; }
  void setNext(Node<T>* next) { this->next = next; }
};

template <typename T>
class Queue {
 private:
  int q_size;
  Node<T>* head;
  Node<T>* tail;

 public:
  // empty
  bool empty() {
    if (q_size == 0)
      return true;
    else
      return false;
  }
  // push
  void push(T data) {
    Node<T>* newNode = new Node(data);
    if (empty()) {
      head = newNode;
      tail = newNode;
    } else {
      tail->setNext(newNode);
      tail = newNode;
    }
    q_size++;
  }
  // pop
  void pop() {
    if (empty()) {
      cout << "pop연산 실패. 큐가 이미 비어있습니다.\n";
      return;
    }
    Node<T>* delNode = head;
    head = head->getNext();
    delete delNode;
    q_size--;
  }
  // front
  T front() { return head->getData(); }
  // size
  int size() { return q_size; }
  // 소멸자
  ~Queue() {
    // 큐가 비어있는데 delete를 시도하면 segmentation error
    if (empty()) return;
    Node<T>* curr = head;
    Node<T>* next = head->getNext();
    delete curr;
    while (next != NULL) {
      curr = next;
      next = next->getNext();
      delete curr;
    }
  }
};

int main() {
  Queue<int> q;
  q.push(2);
  q.push(1);
  q.push(3);
  q.push(4);

  while (!q.empty()) {
    cout << q.front() << '\n';
    q.pop();
  }

  return 0;
}