#include <bits/stdc++.h>

class Node {
  public: 
    int key;
    Node* next;
    Node(int k): key(k), next(NULL) {}
};

void insert(Node** head_ref, int new_key);
void printList(Node* head);
void insertAt(int post, Node** head_ref, int new_key);
void remove(Node** head_ref, int key);
void readNnumbers(Node** head_ref);
void processCommand(char cmd, Node** head_ref);

void processCommand(char cmd, Node** head_ref) {
  int post, key;
  cmd = std::tolower(cmd);
  switch (cmd) {
    case 'i':
      std::cin >> post >> key;
      insertAt(post, head_ref, key);
      break;
    case 'd':
      std::cin >> key;
      remove(head_ref, key);
      break;
  }
  printList(*head_ref);
}

void readNnumbers(Node** head_ref) {
  int n, key;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> key;
    insert(head_ref, key);
  }
}

void printList(Node* head) {
  if (head == NULL) { std::cout << "empty\n"; return; }
  while (head) {
    std::cout << "[" << head->key << "] ";
    head = head->next;
  }
  std::cout << std::endl;
}

void insert(Node** head_ref, int new_key) {
  Node* new_node = new Node(new_key);
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void insertAt(int post, Node** head_ref, int new_key) {
  if (post <= 1 || !*head_ref) {
    insert(head_ref, new_key);
    return;
  }
  
  Node* curr = *head_ref;
  for (int i = 1; curr->next && i < post - 1; i++) {
    curr = curr->next;
  }

  Node* new_node = new Node(new_key);
  new_node->next = curr->next;
  curr->next = new_node;
}

void remove(Node** head_ref, int key) {
  if (!(*head_ref)) {
    std::cout << key << " not existed\n"; 
    return;
  }

  if ((*head_ref)->key == key) {
    Node* curr = (*head_ref);
    (*head_ref) =  (*head_ref)->next;
    std::cout << key << " deleted\n";
    delete curr; 
    return;
  }

  Node* curr = (*head_ref);
  while (curr->next && curr->next->key != key) {
    curr = curr->next;
  }

  if (!curr->next) {
    std::cout << key << " not existed\n";
    return;
  }

  Node* temp = curr->next;
  curr->next = temp->next;
  delete temp;
  std::cout << key << " deleted\n";
}

void freeList(Node* head) {
  while (head) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  Node* head = NULL;
  readNnumbers(&head);
  char command;
  std::cin >> command;
  while (command != 'q') {
    processCommand(command, &head);
    std::cin >> command;
  }
  freeList(head);
  return 0;
}
