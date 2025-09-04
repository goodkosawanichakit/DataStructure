#include <iostream>

class Node {
  public:
    int data;
    Node* next;

  Node(int x){
    data = x;
    next = NULL;
  }
  ~Node(){
  }

};

class linkedlist {
  private:
    Node* head = NULL;

    bool exists(int target){
      Node* temp = head;
      while(temp != NULL){
        if(temp->data == target){
          return 1;
        }
        temp = temp->next;
      }
      return 0;
    }

    void first_node(int x){
      head = new Node(x);
    }

    void insert_end(int x){
      Node* temp = head;
      while(temp->next != NULL){
        temp = temp->next;
      }
      
      temp->next = new Node(x);
    }

    void insert_before(int x, int target){

      if (head->data == target) {
        Node* new_node = new Node(x);
        new_node->next = head;
        head = new_node;
        return;
      }

      Node* curr = head;
      while (curr->next != NULL && curr->next->data != target) {
          curr = curr->next;
      }

      if (curr->next != NULL) {
          Node* new_node = new Node(x);
          new_node->next = curr->next;
          curr->next = new_node;
          return;
      }

      if (!exists(target)) {
        insert_end(x);
      }
    }

    void insert_after(int x, int target){
      Node* curr = head;
      while (curr->next != NULL && curr->data != target) {
        curr = curr->next;
      }

      if(curr->next == NULL){
        Node* new_node = new Node(x);
        curr->next = new_node;
        return;
      }

      if (curr->next != NULL) {
        Node* new_node = new Node(x);
        new_node->next = curr->next;
        curr->next = new_node;
        return;
      }

      if (!exists(target)) {
        insert_end(x);
      }
    }

  public:
    void insert(char flag, int x, int target) {
      if(head == NULL) {
        first_node(x);
        print();
        return;
      }

      if(!exists(target)) {
        insert_end(x);
        print();
        return;
      }

      switch(flag) {
        case 'A':
          insert_after(x, target);
          print();
          break;
        case 'I':
          insert_before(x, target);
          print();
          break;
        default:
          std::cout << "Unreachable!" << std::endl;
      }
    }

    void delete_node(int target){
      if(!exists(target) || head == NULL){
        std::cout << "-1" << std::endl;
        return;
      }

      if (head->data == target) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
      }

      Node* curr = head;
      while(curr->next != NULL && curr->next->data != target){
        curr = curr->next;
      }

      if (curr->next != NULL) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
      }
    }

    void print(){
      Node* temp = head;
      while(temp != NULL){
        std::cout << temp->data << ' ';
        temp = temp->next;
      }
      std::cout << std::endl;
    }
};

int main(){
  linkedlist link_1;
  char flag;
  int x;
  int y;
  while(true){
    std::cin >> flag;

    switch(flag) {
      case 'A':
        std::cin >> x;
        std::cin >> y;
        link_1.insert(flag, x, y);
        continue;
      case 'I':
        std::cin >> x;
        std::cin >> y;
        link_1.insert(flag, x, y);
        continue;
      case 'D':
        std::cin >> x;
        link_1.delete_node(x);
        link_1.print();
        continue;
      case 'E':
        return 0;
    }
  }

  return 0;
}