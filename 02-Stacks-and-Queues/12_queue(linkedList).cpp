#include<iostream>
using namespace std;

class QueueLinkedlist{
private:
  struct node{
  int data;
  node* next;
  };
  node* front;
  node* rear;
  int size = 0;
public:
  QueueLinkedlist(){
    front = NULL;
    rear = NULL;
  }
  ~QueueLinkedlist(){
    while(front!=NULL){
      node * ptr = front;
      front = front->next;
      delete(ptr);
    }
  }

  bool isEmpty(){
    return (front==NULL); //or size==0 OR front == NULL
  }

  void enqueue(int x){ //adding element at the end O(1)
    if (front == NULL){ //if adding first element
      front = new node();
      front->data = x;
      front->next = NULL;
      rear = front;
      size++;
    }
    else{

    //adding nonfirst element (only play with rear as adding at rear end)
    rear->next = new node();
    rear = rear->next;
    rear->next = NULL;
    rear->data= x;
    size++;
    }
    
  }

  void dequeue(){
      if (isEmpty()){
        cout << "Queue is empty...";
      }
      else{
        node* ptr = front;
        front = front->next;
        cout << "element dequeued : "<<ptr->data << endl;
        delete(ptr);
        size--;
      }
  }

  void Size(){
    cout << "size is: "<< size<<endl;
  }

  void peekfront(){
    if (isEmpty()){
      cout << "queue is empty..."<<endl;
    }
    else{
    cout << "peeking front: " << front->data << endl;
    }
}

  void peekrear(){
    if (isEmpty()){
      cout << "queue is empty..."<<endl;
    }
    else{
    cout << "peeking rear: " << rear->data << endl;
    }
  }

  void traverse(){
    if (isEmpty()){
      cout << "queue is empty..."<<endl;
    }
    node* ptr = front;
    while (ptr !=NULL){
      cout << ptr->data << " " ;
      ptr = ptr->next;
      
    }
    cout << endl;
  }

};


int main(){
  QueueLinkedlist q;
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(5);
  q.enqueue(7);
  q.traverse();
  q.Size();
  

  q.dequeue();
  q.dequeue();
  q.traverse();
  q.peekfront();
  q.peekrear();

  q.dequeue();
  q.dequeue();
  q.Size();

  q.dequeue();

  
}