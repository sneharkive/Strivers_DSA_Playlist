// Implement Queue using Linkedlist

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

class Queue{
  public:
    Node* front;
    Node* rear;
    int count;

    Queue(){
      front = NULL;
      rear = NULL;
      count = 0;
    }

    void push(int x){
      Node* ele = new Node(x);

      if(front == NULL){
        front = ele;
        rear = ele;
      }
      else{
        rear -> next = ele;
        rear = ele;
      }
      count++;
    }

    int pop(){
      if(front == NULL) return -1;

      Node* temp = front;
      int topData = temp -> data;
      front = front -> next;

      if (front == NULL) rear = NULL;

      delete temp;
      count--;

      return topData;
    }

    int top(){
      if(front == NULL) return -1;
      return front -> data;
    }

    int size(){
      return count;
    }

    bool isEmpty(){
      return count == 0;
    }
};