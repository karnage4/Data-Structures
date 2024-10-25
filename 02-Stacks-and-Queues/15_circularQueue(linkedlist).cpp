#include<iostream>
using namespace std;

//ALWAYS USE new node(), instead of directly initializing using sir imrans method 
//ALWAYS USE if then else if then else, dont use if,if , can cause errors!

class CircularQueueLL{
private:
  struct node{
  int data;
  node* next;
  };
  
  node* front;
  node* rear;
  int size;
public:
CircularQueueLL(){
  front = NULL;
  rear = NULL;
  size = 0;
}

bool isempty(){
  return (front==NULL);
}

void enqueue(int x){
  if (isempty()){ //for first element
    node* ptr = new node();
    front = ptr;
    rear = ptr;
    rear->next = front; //maintaning circular link
    ptr->data = x;
    size++;
  }
  else{ //normal+circular
    node* ptr = new node();
    rear->next = ptr;
    rear = rear->next;
    ptr->data = x;
    rear->next = front; //maintaining circular link
    size++; 
  }
}

void dequeue(){
  if (isempty()){
    cout <<"Queue is empty...";
  }
  else if (front==rear){ //for pehla element
    node* ptr = new node();
    ptr = front;
    front = NULL;
    rear = NULL;
    cout << "Element dequeued: "<<ptr->data << endl;
    delete(ptr);
    size--;
  }
  else{ //normal+circular
    node* ptr = new node();
    ptr = front;
    front= front->next;
    rear->next = front; //maintaining circular link
    cout << "Element dequeued: "<<ptr->data << endl;
    delete(ptr);
    size--;
  }
}

void sizee(){
  cout << "size of queue is: "<< size << endl;
}

void peekfront(){
  if (isempty()){
    cout <<"Queue is empty...";
  }
  else{
    cout << "peeking front: "<< front->data << endl;
  }
}

void peekrear(){
  if (isempty()){
    cout <<"Queue is empty...";
  }
  else{
    cout << "peeking rear: "<< rear->data << endl;
  }
}

void traverse(){
  if (isempty()){
    cout <<"Queue is empty...";
  }
  else{
    node* ptr= front;
    do {
      cout << ptr->data << " ";
      ptr = ptr->next;
    } while(ptr!= front);
    cout << endl;
  }
}


};

int main(){

  CircularQueueLL q;
  q.enqueue(2);
  q.enqueue(5);
  q.enqueue(7);
  q.enqueue(0);
  q.enqueue(3);
  q.traverse();
  q.peekfront();
  q.peekrear();

  q.dequeue();
  q.dequeue();
  q.traverse();
  q.peekfront();
  q.peekrear();

  q.dequeue();
  q.dequeue();
  q.traverse();
  q.peekfront();
  q.peekrear();

  q.dequeue();
  q.dequeue();

  
}