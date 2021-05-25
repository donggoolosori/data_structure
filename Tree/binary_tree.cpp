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

template <typename T>
void preOrder(Node<T>* node) {}

template <typename T>
void inOrder(Node<T>* node) {}

template <typename T>
void postOrder(Node<T>* node) {}

int main() {
  /*
  아래 모양의 트리 생성
              1
            /    \
          2        3
        /  \     /   \
      4     5   6     7
    /  \
  8      9
  */
  Node<int> root(1);
  Node<int> n2(2);
  Node<int> n3(3);
  Node<int> n4(4);
  Node<int> n5(5);
  Node<int> n6(6);
  Node<int> n7(7);
  Node<int> n8(8);
  Node<int> n9(9);

  root.setLeft(&n2);
  root.setRight(&n3);
  n2.setLeft(&n4);
  n2.setRight(&n5);
  n3.setLeft(&n6);
  n3.setRight(&n7);
  n4.setLeft(&n8);
  n4.setRight(&n9);

  return 0;
}