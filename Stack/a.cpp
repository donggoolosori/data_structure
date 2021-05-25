#include <iostream>

using namespace std;

template <typename T>
class Node {
 private:
  T data;
  Node<T>* next;

 public:
  Node(T data) { this->data = data; }
  Node<T>* getNext() { return next; }
  T getdata() { return data; }
  void setNext(Node<T>* next) { this->next = next; }
};

template <typename T>
class Stack {
 private:
  int stack_size;
  Node<T>* head;

 public:
  Stack() : stack_size(0), head(new Node<T>(0)){};
  // is empty
  bool empty() {
    if (stack_size == 0)
      return true;
    else
      return false;
  }
  // size
  int size() { return stack_size; }
  // push
  void push(T data) {
    stack_size++;
    Node<T>* newNode = new Node(data);
    newNode->setNext(head);
    head = newNode;
  }
  // pop
  void pop() {
    if (empty()) {
      cout << "Stack이 비어있습니다.\n" << '\n';
      return;
    }
    stack_size--;
    Node<T>* temp = head;
    head = head->getNext();
    delete temp;
  }
  // top
  T top() { return head->getdata(); }
  // destructor
  ~Stack() {
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
  Stack<double> stk;
  stk.push(1.2);
  stk.push(2.1);
  stk.push(3.4);
  stk.push(4.7);

  while (!stk.empty()) {
    cout << stk.top() << '\n';
    stk.pop();
  }
  return 0;
}