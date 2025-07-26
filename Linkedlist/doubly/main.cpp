#include <iostream>

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

  Node(int x){
    this->data = x;
    this->next = NULL;
    this->prev = NULL;
  }
  ~Node(){}
};

class Linkedlist {
  private:
    Node* head;
  
    void init(int x) {
      head = new Node(x);
    }

  public:
    void insert_after(int x, int target) {
      if(!head) {
        this->init(x);
        return;
      }
      Node* node = new Node(x);
      
      if (head->data == target ) {
        head->next = node;
        node->prev = head;
        return;
      }
      Node* curr = head;
      while(curr->next != NULL && curr->data != target) {
        curr = curr->next;
      }
      if(curr->next == NULL) {
        curr->next = node;
        node->prev = curr;
        return;
      }
      node->prev = curr;
      node->prev = curr;
      curr->next = node;
      node->next->prev = node;
    }
    void insert_before(int x, int target) {
      if(!head) {
        this->init(x);
        return;
      }

      Node* node = new Node(x);
      
      if (head->data == target) {
        node->next = head;
        head->prev = node;
        head = node;
        return;
      }

      Node* curr = head;
      while(curr->next != NULL && curr->next->data != target) {
        curr = curr->next;
      }

      if(curr->next == NULL) {
        curr->next = node;
        node->prev = curr;
        return;
      }

      node->next = curr->next;
      node->prev = curr;
      curr->next = node;
      node->next->prev = node;
    }

    void insert_after(int x) {
      if(!head) {
        this->init(x);
        return;
      }
    }
};


int main() {
  Linkedlist x;

}