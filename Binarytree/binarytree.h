#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <concepts>
#include <queue>
#include <limits>


template <typename T>
struct Node {
  T data;
  Node* left;
  Node* right;
  Node(T x) { data = x; left = nullptr; right = nullptr;};
};

// template <typename T>
// Node<T>* insert(Node<T>* root);
template <typename T>
void inorder(Node<T>* root);
template <typename T>
void preorder(Node<T>* root);
template <typename T>
void postorder(Node<T>* root);
template <typename T>
void bfs(Node<T>* root);
template <typename T>
void deleteTree(Node<T>* root);
template <typename T>
T findMin(Node<T>* root);
template <typename T>
bool isIdentical(Node<T>* root_1, Node<T>* root_2);
template <typename T>
bool isMirror(Node<T>* root_1, Node<T>* root_2);
template <typename T>
bool isCounsin(Node<T>* root_1, Node<T>* root_2);


// template <typename T>
// Node<T>* insert(Node<T>* root, T x) {
//   if (!root) {
//     return new Node<T>(x);
//   }
//   if (x < root->data) root->left = insert(root->left, x);
//   else root->right = insert(root->right, x);
//   return root;
// }

template <typename T>
void inorder(Node<T>* root) {
  if (!root) return;
  inorder(root->left);
  std::cout << root->data << ' ';
  inorder(root->right);
}

template <typename T>
void preorder(Node<T>* root) {
  if (!root) return;
  std::cout << root->data << ' ';
  preorder(root->left);
  preorder(root->right);
}

template <typename T>
void postorder(Node<T>* root) {
  if (!root) return;
  postorder(root->left);
  postorder(root->right);
  std::cout << root->data << ' ';
}

template <typename T>
void bfs(Node<T>* root) {
  if (!root) throw std::runtime_error("Tree is empty");
  std::queue<Node<T>*> queue;
  queue.push(root);
  do {
    if (queue.front()->left) queue.push(queue.front()->left);
    if (queue.front()->right) queue.push(queue.front()->right);
    std::cout << queue.front()->data << ' ';
    queue.pop();
  } while (!queue.empty());
  return;
}

template <typename T>
void deleteTree(Node<T>* root) {
  if (root == nullptr) {
    return;
  }
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

template <typename T>
T findMin(Node<T>* root) {
  if (!root) throw std::runtime_error("Tree is empty");
  T min;
  std::queue<Node<T>*> queue;
  queue.push(root);
  min = queue.front()->data;
  do {
    if (queue.front()->left) queue.push(queue.front()->left);
    if (queue.front()->right) queue.push(queue.front()->right);
    if (queue.front()->data < min) min = queue.front()->data;
    queue.pop();
  } while (!queue.empty());
  return min; 
}

template <typename T>
bool isIdentical(Node<T>* root_1, Node<T>* root_2) {
  if (!root_1 && !root_2) return true;
  if (!root_1 || !root_2) return false;
  return (root_1->data == root_2->data) &&
  isIdentical(root_1->left, root_2->left) &&
  isIdentical(root_1->right, root_2->right);
}

template <typename T>
bool isMirror(Node<T>* root_1, Node<T>* root_2) {
  if (!root_1 && !root_2) return true;
  if (!root_1 || !root_2) return false;
  return (root_1->data == root_2->data) &&
  isMirror(root_1->left, root_2->right) &&
  isMirror(root_1->right, root_2->left);
}

template <typename T>
bool isCounsin(Node<T>* root, T x, T y) {
  if (!root) throw std::runtime_error("Tree is empty");
}

#endif