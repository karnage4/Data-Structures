#include<iostream>
using namespace std;

class stacklinkedlist{
private:
  struct node{
  int data;
  node* next;
  };

  node* top;
  int size;

public:
stacklinkedlist(){
  top = NULL;
  size = 0;
}

~stacklinkedlist(){
  while(top!=NULL){
    node* ptr = top;
    top = top->next;
    delete(ptr);
  }
}

bool isEmpty(){
  return top==NULL;
}

void push(int x){
  node* ptr = new node();
  ptr->data = x;
  ptr->next = top;
  top = ptr;
  size++;
}

void pop(){
  if (isEmpty()){
    cout << "stack is empty..." << endl;
  }
  else{
    node* ptr = top;
    top = top->next;
    cout<< "Element popped: " << ptr->data << endl;
    delete(ptr);
    size--;
  }
}

void sizeofstack(){
  cout << "Size of stack is: " <<size<<endl;
}

//this whole code depends how is the positioning working 
void peek(int position){
  node* ptr = top;
  if (isEmpty()){
    cout << "stack is empty..." << endl;
  }
  else{
    for (int i=0; i<position-1 && ptr!=NULL; i++){
      ptr = ptr->next;
    }
  }
  if (ptr!=NULL){
    cout << "Peeking at index "<<position<< " : "<< ptr->data << endl;
  }
  else{
    cout << "This position is out of bound..." << endl;
  }
}

void stacktop(){
  cout << "Top of stack is: " << top->data << endl;
}

void stackBottom(){
  node* ptr = top;
  while(ptr->next!=NULL){
    ptr = ptr->next;
  }
  cout << "Bottom of stack: " << ptr->data << endl;
}

void traversal(){
  node* ptr = top;
  if(isEmpty()){
    cout << "Stack is empty..." << endl;
  }
  else{
    while(ptr->next != NULL){
      cout << ptr->data << endl;
      ptr = ptr->next;
    }
    cout << ptr->data <<endl;
    cout <<endl;
  }
}
};

int main(){
  stacklinkedlist s;
  s.push(5);
  s.push(7);
  s.push(8);
  s.push(11);
  s.traversal();
  s.sizeofstack();
  s.stacktop();
  s.stackBottom();

  s.pop();
  s.traversal();
  s.sizeofstack();

  s.pop();
  s.pop();
  s.pop();
  s.traversal();
  s.sizeofstack();

}