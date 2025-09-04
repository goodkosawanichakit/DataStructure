#include <iostream>
#include "binarytree.h"

int main() {
  /*
        10
       /   \
     20     30
    /  \   /  \
   40  50 60  70
        10
       /   \
     30     20
    /  \   /  \
   70  60 50  40
  */
  Node<int>* root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  Node<int>* root1 = new Node(10);
  root1->left = new Node(30);
  root1->right = new Node(20);
  std::cout << isMirror(root, root1) << std::endl;
  delete(root);
  delete(root1);
  return 0;
}
