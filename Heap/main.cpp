#include <bits/stdc++.h>

/* Maxsize of Heap */
#define MAX_SIZE 100

/* Heap Structure */
struct Heap {
  int *arr = NULL;
  int size;
};

/* function prototype */
void initHeap(Heap*& heap, int capacity);
void insert(Heap* heap, int value);
void heapifyUp(Heap* heap, int index);
void heapifyDown(Heap* heap);
int del(Heap* heap);


void initHeap(Heap*& heap, int capacity) {
  heap = new Heap;
  heap->arr = new int[capacity];
  heap->size = -1;
}
void insert(Heap* heap, int value) {
  heap->arr[++(heap->size)] = value; 
  heapifyUp(heap, heap->size); 
} 
  
void heapifyUp(Heap* heap, int index) { 
  while (index > 0 && heap->arr[index] > heap->arr[index/ 2]) { 
    std::swap(heap->arr[index], heap->arr[index / 2]); 
    index /= 2; 
  } 
}

int del(Heap* heap) {
  int return_value = heap->arr[0];
  heap->arr[0] = heap->arr[heap->size--];
  heapifyDown(heap);
  return return_value;
}

void heapifyDown(Heap* heap) {
  int index = 0;
  int largest, left, right;
  while (index < heap->size) {
    left = 2 * index + 1;
    right = 2 * index + 2;
    largest = index;
    if (left <= heap->size && heap->arr[left] > heap->arr[largest]) largest = left;
    else if (right <= heap->size && heap->arr[right] > heap->arr[largest]) largest = right;
    else if (largest == index) break;
    std::swap(heap->arr[index], heap->arr[largest]);
    index = largest;
  }
}

void print(Heap* heap) {
  for(int i = 0; i <= heap->size; i++) {
    std::cout << heap->arr[i] << ' ';
  }
  std::cout << std::endl;
}

int main() {
  Heap* heap ;
  initHeap(heap, MAX_SIZE);
  char cmd;
  int value;
    while (std::cin >> cmd) {
      if (cmd == 'a') {
        std::cin >> value;
        insert(heap, value);
      } 
      else if (cmd == 'd') {
        if (heap->size >= 0) {
          std::cout << del(heap) << std::endl;
        }
      } 
      else if (cmd == 'p') {        
        print(heap);
      } 
      else if (cmd == 'e') {        
        break;
      }
  }

  delete[] heap->arr; 
  delete heap;
  return 0;
}