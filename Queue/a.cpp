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
  Node<T>* getNext(){return next};
  void setNext(Node<T>* next){this->next = next};
};

int main() { return 0; }