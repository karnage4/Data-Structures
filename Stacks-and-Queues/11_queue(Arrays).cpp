#include<iostream>
using namespace std;

class queue{ //all customised data structures will be made in heap such as stack and queue
  int* arr;
  int front;
  int rear;
  int n;
public:

queue(int size){
  n = size;
  arr = new int[n];
  front = -1;
  rear = -1;
}

bool isFull(){
  return (rear == n - 1);
}

bool isEmpty(){
  return (front == -1 && rear == -1);
}

void enqueue(int x){
  if (isFull()){
    cout << "Queue is full..." << endl;
  }
  if (isEmpty()){
    front = 0;
    rear = 0;
    arr[rear] = x;
  }
  else{
    arr[++rear] = x;
  }
}

void dequeue(){
  if (isEmpty()){
    cout << "Queue is empty..." << endl;
  }
  if (front == rear){ //one first element left so reset Q
    cout << "element removed is "<< arr[front]<< endl;
    front = -1;
    rear = -1 ;
  }
  else{
    cout << "element removed is "<< arr[front]<< endl;
    front++;
  }
}

void traversal(){
  if (isEmpty()){
    cout << "queue is empty..." << endl;
  }
  else{
    for (int i=front; i<=rear; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}

void peekfront(){
  cout <<"front is: "<< arr[front] << endl;
}

void peekrear(){
  cout << "rear is: " << arr[rear] << endl;
}
};

int main(){
  queue q(5);
  q.enqueue(7);
  q.enqueue(9);
  q.enqueue(11);
  q.enqueue(13);
  q.traversal();
  q.peekfront();
  q.peekrear();

  q.dequeue();
  q.dequeue();
  q.traversal();

  q.dequeue();
  q.dequeue();
  q.traversal();
}