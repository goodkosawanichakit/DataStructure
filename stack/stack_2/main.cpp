#include <iostream>

class Stack{
  private:
    int top = -1;
    int size = 0;
    int *stack = NULL;
    
    bool isfull(){
      if((top + 1) == size){
        return true;
      }
      return false;
    }
    
    bool isempty(){
      if(top == -1){
        return true;
      }
      return false;
    }

    void resize(){
      size *= 2;
      int* temp = new int[size];
        int i;
        for(i = 0; i < (top + 1); i++){
          temp[i] = stack[i];
        }
        delete[] stack;
        stack = temp;
    }

  public:
    ~Stack() {
      delete[] stack; 
    }

    void push(int x){
      if(size == 0){
        stack = new int[1];
        top++;
        stack[top] = x;
        size++;
      }
      else if(isfull()){
        resize();
        stack[++top] = x;
      }
      else if(!isfull()) {
        stack[++top] = x;
      }
      return;
    }

    void print(){
      if(isempty()){
        std::cout << "-1" << std::endl;
      }
      for(int i = 0; i < (top + 1); i++){
        std::cout << stack[i] << ' ';
      }
      std::cout << std::endl;
    }

    void peaktop(){
      std::cout << stack[top] << std::endl;
    }

    void pop(){
      std::cout << stack[top--] << std::endl;
    }

    void showsize(){
      std::cout << top << std::endl;
    }

};

int phrase(std::string &input){
  int size = input.size();
  std::string number;
  int number_size = 0;
  for(int i = 0; i < size; i++){
    if(input[i] > 47 && input[i] <58){
      number.push_back(input[i]);
    }
  }
  return std::stoi(number);
}

int main(){

  Stack stack;
  std::string input;

  while(true){
    getline(std::cin, input);
    switch(input[0]){
      case 'X':
        break;
      case 'U':
        stack.push(phrase(input));
        continue;
      case 'O':
        stack.pop();
        continue;
      case 'T':
        stack.peaktop();
        continue;
      case 'N':
        stack.showsize();
        continue;
      case 'P':
        stack.print();
        continue;
      default:
        std::cout << "There's no " << input[0] << " in the function call\n";
        continue;
    }
    break;
  }
  return 0;
}