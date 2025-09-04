#include <bits/stdc++.h>
#define SIZE 5

class queue {
  private:
    int arr[SIZE];
    int front, rear, count;
  public:

    bool isfull() { return count == SIZE; }
    bool isempty() { return count == 0; }
    
    void enqueue(int x) {
      if (isfull()) { std::cout << "Queue Full\n"; return; }
      rear = (rear + 1) % SIZE;
      arr[rear] = x;
      count++;
      std::cout << "f:" << front << " r:" << rear << std::endl;
    }

    void dequeue() {
      if (isempty()) { std::cout << "Queue Empty\n"; return; }
      int val = arr[front];
      front = (front + 1) % SIZE;
      count--;
      std::cout << val << " f:" << front << " r:" << rear << std::endl;
    }

    queue () {
      front = 2;
      rear = 1;
      count = 0;
    }
};

int main() {
  queue a;
  a.enqueue(2);
  a.enqueue(3);
  a.enqueue(4);
  a.dequeue();
  a.dequeue();
  a.dequeue();
  return 0;
}