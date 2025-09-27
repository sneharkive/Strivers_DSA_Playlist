// Implement Stack using Linked List

#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int d){
      data = d;
      next = NULL;
    }
};

class Stack{
  public:
    Node* top;
    int count;

    Stack() {
      top = NULL;
      count = 0;
    }

    void push(int d){
      Node* ele = new Node(d);
      ele -> next = top;

      top = ele;
      count++;
    }

    int pop(){
      if (top == NULL) return -1;
      
      int topEle = top -> data;
      Node* temp = top;
      top = top -> next;

      delete temp;
      count--;

      return topEle;
    }

    int size() {
      return count;
    }

    bool isEmpty() {
      return top == NULL;
    }

    int top() {
      if (top == NULL) return -1;
      return top -> data;
    }
};

