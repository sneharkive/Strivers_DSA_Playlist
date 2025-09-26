// Implement Queue Using Array

#include <iostream>
using namespace std;

class Queue {
  int *arr;
  int start, end, maxSize, currSize;

  public:
    Queue(){
      maxSize = 100;
      arr = new int[maxSize];
      start = -1;
      end = -1;
      currSize = 0;
    }

    Queue(int size){
      ( * this).maxSize = size;
      arr = new int[maxSize];
      start = -1;
      end = -1;
      currSize = 0;
    }

  void push(int data){
    if(currSize == maxSize) {
      cout << "Queue is Full" << endl;
      return;
    }
    if(end == -1){
      end = 0;
      start = 0;
    }
    else end = (end + 1) % maxSize;

    arr[end] = data;
    currSize++;
  }

  int pop(){
    if(currSize == 0) { //  || start == -1
      cout << "Queue is Empty" << endl;
      return;
    }
    
    int r = arr[start];
    if(currSize == 1){
      start = -1;
      end = -1;
    }
    else start = (start - 1) % maxSize;

    currSize--;
    return r;
  }

  int top(){
    if(currSize == 0) { //  || start == -1
      cout << "Queue is Empty" << endl;
      return;
    }
    return arr[start];
  }

  int size(){
    return currSize;
  }

};