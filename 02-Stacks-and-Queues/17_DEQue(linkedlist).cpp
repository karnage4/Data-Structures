#include<iostream>
using namespace std;


class DEQueueLL{
private:
struct node{
  int data;
  node* next;
  node* prev;
  };
  
  node* front;
  node* rear;
  int size;

public:
DEQueueLL(){
  front = NULL;
  rear = NULL;
  size = 0;
}

~DEQueueLL(){
  while(!isempty()){
    DEQueueLLFront();
  }
}

bool isempty(){
  return (front==NULL);
}

void enqueueFront(int x){
  if (isempty()){
    node* ptr = new node();
    front = ptr;
    rear = ptr;
    rear->next = front; //circular link
    front->prev = rear; //circular link
    ptr->data = x;
    size++;
  }
  else{
    node* ptr = new node();
    front->prev = ptr; //link front to ptr
    ptr->next = front; //link ptr to front
    front = ptr;
    front->prev = rear; //circular link
    rear->next = front; // circular link
    ptr->data = x;
    size++;
    
  }
}

void enqueueRear(int x){
  if (isempty()){
    node* ptr = new node();
    rear = ptr;
    front = ptr;
    rear->next = front; //circular link
    front->prev = rear; //circular link
    ptr->data = x;
    size++;
  }
  else{
    node* ptr = new node();
    rear->next = ptr; //link rear to ptr
    ptr->prev = rear; //link ptr to rear
    rear = rear->next; 
    rear->next = front; //circular link
    front->prev = rear; //circular link
    ptr->data = x;
    size++;
  }
}

void DEQueueLLFront(){
  if (isempty()){
    cout << "deque is empty..."<<endl;
  }
  else if (front == rear){
    node* ptr = new node();
    ptr = front ;
    front = NULL;
    rear = NULL;
    cout << "element DEQueueLLd: "<<ptr->data <<endl;
    delete(ptr);
    size--;
    
  }
  else{
    node* ptr = new node();
    ptr = front;
    front = front->next;
    cout << "element DEQueueLLd: "<<ptr->data << endl;
    delete(ptr);
    front->prev = rear; //circular link
    rear->next = front; //circular link
    size--;
    
  }
}

void DEQueueLLRear(){
  if (isempty()){
    cout << "deque is empty..."<<endl;
  }
  else if (front == rear){
    node* ptr = new node();
    ptr = rear;
    rear = NULL;
    front = NULL;
    cout << "element DEQueueLLd: "<<ptr->data << endl;
    delete(ptr);
    size--;
  }
  else{
    node* ptr = new node();
    ptr = rear;
    rear = rear->prev;
    cout << "element DEQueueLLd: "<<ptr->data << endl;
    delete(ptr);
    rear->next = front; //circular link
    front->prev = rear; //circular link
    size--;
  }
}

void sizee(){
  if (isempty()){
    cout << "deque is empty..."<<endl;
  }
  else{
    cout << "size : "<< size << endl;
  }
}

void peekfront(){
  if (isempty()){
    cout << "deque is empty..."<<endl;
  }
  else{
    cout << "peeking front: "<< front->data << endl;
  }
  
}

void peekrear(){
  if (isempty()){
    cout << "deque is empty..."<<endl;
  }
  else{
    cout << "peeking rear: " << rear->data << endl;
  }
}

void traverse(){
  if (isempty()){
    cout << "deque is empty..."<<endl;
  }
  else{
    node* ptr = new node();
    ptr = front;
    do {
      cout << ptr->data << " ";
      ptr = ptr->next;
    } while(ptr!= front);
    cout << endl;
  }
}

};




int main(){

  DEQueueLL q;
  q.enqueueRear(3);
  q.enqueueRear(5);
  q.enqueueRear(7);
  q.traverse();
  q.peekfront();
  q.peekrear();

  q.enqueueFront(1);
  q.enqueueFront(2);
  q.traverse();
  q.peekfront();
  q.peekrear();

  q.DEQueueLLRear();
  q.DEQueueLLRear();
  q.traverse();
  q.peekfront();
  q.peekrear();

  q.DEQueueLLFront();
  q.DEQueueLLFront();
  q.traverse();
  q.peekfront();
  q.peekrear();

  q.DEQueueLLFront();

  // q.DEQueueLLRear();
  q.DEQueueLLFront();
}