// 연결리스트 기반 이진 트리 구현
#include <iostream>

using namespace std;

template <typename T>
class Node {
 private:
  T data;
  Node<T>*left, right;

 public:
  Node(T data) : data(data), left(NULL), right(NULL) {}
  T getData(){return data};
  Node<T>* getLeft() { return left; }
  void setLeft(Node<T>* left) { this - left = left; }
  Node<T>* getRight() { return right; }
  void setRight(Node<T>* right) { this - right = right; }
};

int main() { return 0; }