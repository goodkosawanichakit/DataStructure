#include <iostream>
#include <vector>

void menu();

class Stack{
  private:
    int top = -1;
    int *stack;

  public:
    void push(int x){
      if(top == -1){
        stack = new int(1);
        top++;
      }
    }
    void isfull()
};


int main(){

  Stack stack;
  std::string input;

  while(true){
    getline(std::cin, input);
    if(input[0] == 'X'){
      break;
    }
    std::cout << "what\n"; 
  }
  return 0;
}