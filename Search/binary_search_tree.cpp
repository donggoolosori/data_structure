#include <iostream>

using namespace std;

class BST {
  int data;
  BST *left, *right;

 public:
  // default constructor
  BST();
  // paramiterized constructor
  BST(int);
  // insert function
  BST* insert(BST*, int);
  // Inorder traversal
  void inorder(BST*);
};

// BST::BST() : data(0), left(NULL), right(NULL) {}

BST::BST(int data) : data(data), left(NULL), right(NULL) {}

BST* BST::insert(BST* root, int data) {
  if (root == NULL) {
    return new BST(data);
  }

  if (data > root->data) {
    root->right = insert(root->right, data);
  } else {
    root->left = insert(root->left, data);
  }

  return root;
}

void BST::inorder(BST* root) {
  if (root == NULL) return;

  inorder(root->left);
  cout << root->data << '\n';
  inorder(root->right);
}

int main() {
  BST bst, *root = NULL;
  root = bst.insert(root, 50);

  bst.insert(root, 30);
  bst.insert(root, 20);
  bst.insert(root, 40);
  bst.insert(root, 70);
  bst.insert(root, 60);
  bst.insert(root, 80);

  bst.inorder(root);

  return 0;
}