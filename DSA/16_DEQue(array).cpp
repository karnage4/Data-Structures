#include<iostream>
using namespace std;


//NEW ADDITIONS: enqueueFront() and dequeueRear()

class DEQueArray{
  private:
int* arr;
int front;
int rear;
int size;
public:
DEQueArray(int n){
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

//NEW ADDITION
void enqueueFront(int x){
  if (isfull()){
    cout << "deque is full..." << endl;
  }
  else if (isempty()){
    front = 0;
    rear =0;
    arr[front]= x;
  }
  else{
    front = (front-1+size)%size; //circular decrement also considering negative index
    arr[front] = x;
  }
}

void enqueueRear(int x){
  if (isfull()){
    cout << "deque is full..." << endl;
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


void dequeueFront(){
  if(isempty()){
    cout << "deque is empty..."<<endl;
  }
  else if (front==rear){ //for last element remaing so we reset the Q
    cout << "Element dequeueFrontd is: "<<arr[front] <<endl;
    front = -1;
    rear = -1;
  }
  else{
    cout << "Element dequeueFrontd is: "<<arr[front] <<endl;
    front = (front+1)%size; //circular increment for front

  }

}

//NEW ADDITION 
void dequeueRear(){
  if (isempty()){
    cout << "deque is empty..."<<endl;
  }
  else if (front==rear){ //reset queue if one element
    cout << "element dequeued is : "<<arr[rear]<<endl;
    front = -1;
    rear = -1;
  }
  else{
    cout << "element dequeued is : "<<arr[rear]<<endl;
    rear = (rear-1+size)%size; //circular decrement;
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
    cout << "deque is empty..."<<endl;
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
  DEQueArray q(5);
  q.enqueueRear(2);
  q.enqueueRear(5);
  q.enqueueRear(7);
  q.traverse();
  q.peekfront();
  q.enqueueFront(1);
  q.traverse();
  q.peekfront();

  q.enqueueRear(6);
  q.traverse();
  q.enqueueRear(9);
  q.peekfront();
  q.peekrear();

  q.dequeueRear();
  q.dequeueRear();
  q.traverse();
  q.peekrear();

  q.dequeueFront();
  q.traverse();
  q.peekfront();

  q.dequeueRear();
  q.dequeueRear();

  q.dequeueFront();
  
}
