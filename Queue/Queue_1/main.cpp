#include <iostream>

class Queue{
  private:
    int front = 0;
    int tail = 0;
    int capacity = 0;
    int *queue = NULL;

    void new_queue(){
      queue = new int[++capacity];
    }

    void resize(){
      int* temp = new int[++capacity];
      int i;
      for(i = 0; i < tail; i++){
        temp[i] = queue[i];
      }
      delete[] queue;
      queue = temp;
    }

    bool isfull(){
      return tail == capacity - 1;
    }

    bool isempty(){
      return front == tail;
    }

  public:
    ~Queue() {
      delete[] queue; 
    }
    void enqueue(int x){
      if(capacity == 0){
        new_queue();
        queue[tail++] = x; 
        return;
      }
      else if(isfull()){
        resize();
        queue[tail++] = x;
        return;
      }
      queue[tail++] = x;
    }
    
    void print(){
      int i;
      if(isempty()){
        std::cout << "-1" << std::endl;
        return;
      }
      for(i = front; i < tail; i++){
        std::cout << queue[i] << ' ';
      }
      std::cout << std::endl;
    }

    void show_size(){
      std::cout << tail << std::endl;
    }

    void first_last(){
      std::cout << queue[front] << ' ' << queue[tail - 1] << std::endl;
    }

    void dequeue(){
      if(isempty()){
        return;
      }
      std::cout << queue[front] << std::endl;
      int temp = front;
      while (temp < tail){
        queue[temp++] = queue[temp + 1];
      }
      tail--;
      return;
    }
};

int phrase(std::string &input){
  int size = input.size();
  std::string number;
  for(int i = 0; i < size; i++){
    if(input[i] > 47 && input[i] <58){
      number.push_back(input[i]);
    }
  }
  return std::stoi(number);
}

int main(){

  Queue queue;
  std::string input;

  while(true){
    getline(std::cin, input);
    switch(input[0]){
      case 'x':
        break;
      case 'e':
        queue.enqueue(phrase(input));
        continue;
      case 'p':
        queue.print();
        continue;
      case 'd':
        queue.dequeue();
        continue;
      case 'n':
        queue.show_size();
        continue;
      case 's':
        queue.first_last();
        continue;
      default:
        std::cout << "There's no " << input[0] << " in the function call\n";
        continue;
    }
    break;
  }
  return 0;
}