// 연결리스트 기반 이진 트리 구현
#include <iostream>

using namespace std;

class Node {
 private:
  int data;
  Node* left;
  Node* right;

 public:
  Node(int data) : data(data), left(NULL), right(NULL) {}
  int getData() { return data; }
  Node* getLeft() { return left; }
  void setLeft(Node* left) { this->left = left; }
  Node* getRight() { return right; }
  void setRight(Node* right) { this->right = right; }
};

// 전위 순회
void preOrder(Node* root) {
  if (root == NULL) return;
  cout << root->getData() << ' ';
  preOrder(root->getLeft());
  preOrder(root->getRight());
}
// 중위 순회
void inOrder(Node* root) {
  if (root == NULL) return;
  inOrder(root->getLeft());
  cout << root->getData() << ' ';
  inOrder(root->getRight());
}
// 후위 순회
void postOrder(Node* root) {
  if (root == NULL) return;
  postOrder(root->getLeft());
  postOrder(root->getRight());
  cout << root->getData() << ' ';
}

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
  Node root(1);
  Node n2(2);
  Node n3(3);
  Node n4(4);
  Node n5(5);
  Node n6(6);
  Node n7(7);
  Node n8(8);
  Node n9(9);

  root.setLeft(&n2);
  root.setRight(&n3);
  n2.setLeft(&n4);
  n2.setRight(&n5);
  n3.setLeft(&n6);
  n3.setRight(&n7);
  n4.setLeft(&n8);
  n4.setRight(&n9);

  cout << "전위 순회: ";
  preOrder(&root);
  cout << '\n';
  cout << "중위 순회: ";
  inOrder(&root);
  cout << '\n';
  cout << "후위 순회: ";
  postOrder(&root);

  return 0;
}