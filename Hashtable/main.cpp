#include <iostream>
#include <sstream>

class Node {
  public:
    int key;
    std::string value;
    Node* next;

  Node(int x, std::string data) {
    key = x;
    value = data;
    next = NULL;
  }
};

class linkedlist {
  private:
    Node* head = NULL;

    void first_node(int key, std::string value) {
      head = new Node(key, value);
      return;
    }
  public:
    
    void insert(int key, std::string value) {
      if (head == NULL) {
        first_node(key, value);
        return;
      }
      Node* curr = head;
      while (curr->next != NULL && curr->key != key) {
        curr = curr->next;
      }
      if(curr->key == key) {
        curr->value = value;
        return;
      }
      Node* new_node = new Node(key, value);
      curr->next = new_node;
      return;
    }

    void print() {
      Node *curr = head;
      if(curr == NULL) {
        std::cout << "(-1,-)" << std::endl;
        return;
      }
      while(curr != NULL) {
        std::cout << '(' << curr->key << ',' << curr->value << ')' << ' ';
        curr = curr->next;
      }
      std::cout << std::endl;
    }

    void find(int key) {
      Node *curr = head;
      if(curr == NULL) {
        std::cout << '-' << std::endl;
        return;
      }
      while(curr->next != NULL && curr->key != key) {
        curr = curr->next;
      }
      std::cout << curr->value << std::endl;
    }

};

class Hash {
  private:
    linkedlist table[17];

    inline int hash(int key) {
      return key % 17;
    }

  public:
    void insert(int key, std::string value) {
      int index = hash(key);
      table[index].insert(key, value);
      return;
    }

    void print() {
      for(int i = 0; i < 17; i++) {
        table[i].print();
      }
      return;
    }

    void find(int key) {
      int index = hash(key);
      table[index].find(key);
      return;
    }
};

int main() {
  std::string input;
  Hash hash;
  char command;
  int key;
  std::string value;
 
  while(true) {
    getline(std::cin, input);
    std::istringstream iss(input);
    iss >> command >> key >> value;
    
    switch(command) {
      case 'e':
        return 0;
      case 'a':
        hash.insert(key, value);
        continue;
      case 's':
        hash.find(key);
        continue;
      case 'p':
        hash.print();
        continue;
    }
  } 
  return 0;
}