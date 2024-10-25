#include<iostream>
using namespace std;

class CircularQueue{
  private:
int* arr;
int front;
int rear;
int size;
public:
CircularQueue(int n){
  size = n;
  arr = new int[size];
  front = -1;
  rear = -1;
}

bool isempty() {
  return (front==-1 && rear==-1);
}

bool isfull(){
  return ((rear+1)%size == front);
}

void enqueue(int x){
  if (isfull()){
    cout << "Queue is full..." << endl;
  }
  else if (isempty()){ //for pehla element
    front = 0;
    rear = 0;
    arr[rear] = x;
  }
  else{ //for normal + circular case
    rear = (rear+1)%size; //circular increment for rear
    arr[rear] = x;
  }
}

void dequeue(){
  if(isempty()){
    cout << "Queue is empty..."<<endl;
  }
  else if (front==rear){ //for last element remaing so we reset the Q
    cout << "Element dequeued is: "<<arr[front] <<endl;
    front = -1;
    rear = -1;
  }
  else{
    cout << "Element dequeued is: "<<arr[front] <<endl;
    front = (front+1)%size; //circular increment for front
  
  }
  
}

void peekfront(){
  cout << "peeking front: "<< arr[front]<<endl;
}

void peekrear(){
  cout << "peeking rear: "<< arr[rear]<<endl;
}

void traverse(){
  if(isempty()){
    cout << "Queue is empty..."<<endl;
  }
  
  int i = front;
  while (true){ //as Q can be circular we will use circular incrementing for all cases
    cout << arr[i]<<" ";
    
    if (i==rear){ //base case
      break;
    }
    i = (i+1)%size; //circular incrementing
  }
  cout << endl;
  }

};

int main(){
  CircularQueue q(5);
  q.enqueue(2);
  q.enqueue(5);
  q.enqueue(7);
  q.enqueue(0);
  q.traverse();
  q.peekfront();
  q.peekrear();

  q.enqueue(3);
  q.traverse();

  q.dequeue();
  q.dequeue();
  q.traverse();

  q.enqueue(1); //circulating here, rear comes at index 0
  q.traverse();

  q.enqueue(8);
  q.traverse();
  q.peekfront();
  q.peekrear();
  
  q.enqueue(6);
  
}
