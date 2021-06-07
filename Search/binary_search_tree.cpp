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
  // find min value BST node
  BST* minValueNode(BST*);
  // erase function
  BST* erase(BST*, int);
  // Inorder traversal
  void inorder(BST*);
};

BST::BST() : data(0), left(NULL), right(NULL) {}

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

BST* BST::minValueNode(BST* root) {
  BST* ret = root;

  while (ret && ret->left != NULL) {
    ret = ret->left;
  }

  return ret;
}

BST* BST::erase(BST* root, int data) {
  // base case
  if (root == NULL) return root;

  // if the data to be deleted is
  // smaller than the root's data,
  // then it lies in left subtree.
  if (data < root->data) root->left = erase(root->left, data);

  // if the data to be deleted is
  // bigger than the root's data,
  // then it lies in right subtree.
  else if (data > root->data)
    root->right = erase(root->right, data);

  // if the data is same as root's data,
  // then this is the node to be deleted.
  else {
    // 단말노드일 경우
    if (root->left == NULL && root->right == NULL) {
      return NULL;
    }
    // 오른쪽 자식노드만 존재할 경우
    else if (root->left == NULL) {
      BST* temp = root->right;
      delete root;
      return temp;
    }
    // 왼쪽 자식노드만 존재할 경우
    else if (root->right == NULL) {
      BST* temp = root->left;
      delete root;
      return temp;
    }
    // 왼쪽 오른쪽 자식노드 둘 다 존재할 경우
    // find the smallest in the right subtree
    BST* temp = minValueNode(root->right);
    // copy
    root->data = temp->data;
    // delete
    root->right = erase(root->right, temp->data);
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

  bst.erase(root, 40);

  bst.inorder(root);

  return 0;
}