// Implement Stack using Array

#include <iostream>
using namespace std;

class Stack {
  int *arr;
  int top, size;

  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }

  void push(int data){
    top++;
    arr[top] = data;
  }

  int pop() {
    int x = arr[top];
    top--;
    return x;
  }

  int top(){
    return arr[top];
  }
  
  int Size() {
    return top + 1;
  }
};
