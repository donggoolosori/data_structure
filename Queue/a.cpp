#include <iostream>

using namespace std;

template <typename T>
class Node {
 private:
  T data;
  Node<T>* next;

 public:
  Node(T data) { this->data = data; }
  T getdata() { return data; }
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
  // 생성자
  Queue() : q_size(0), head(NULL), tail(NULL) {}
  // empty
  bool empty() {
    if (q_size == 0)
      return true;
    else
      return false;
  }
  // push
  void push(T data) {
    q_size++;
    Node<T>* newNode = new Node(data);
    if (empty()) {
      head = newNode;
      tail = newNode;
    } else {
      tail->setNext(newNode);
      tail = newNode;
    }
  }
  // pop
  void pop() {
    if (empty()) {
      cout << "pop연산 실패. 큐가 이미 비어있습니다.\n";
      return;
    }
    q_size--;
    Node<T>* delNode = head;
    head = head->getNext();
    delete delNode;
  }
  // front
  T front() { return head->getdata(); }
  // size
  int size() { return q_size; }
  // 소멸자
  ~Queue() {
    Node<T>* curr = head;
    Node<T>* next = head->getNext();

    while (next != NULL) {
      delete curr;
      curr = next;
      next = next->getNext();
    }
    delete curr;
  }
};

int main() {
  Queue<int> q;
  q.push(2);
  q.push(1);
  q.push(3);

  while (!q.empty()) {
    cout << q.front() << '\n';
    q.pop();
  }

  return 0;
}