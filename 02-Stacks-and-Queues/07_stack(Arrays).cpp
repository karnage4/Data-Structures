#include<iostream>
using namespace std;

class stack{
int* arr;
int top;
int size;

public:
stack(int n){
  size = n;
  arr = new int[size];
  top = -1;
}

bool isEmpty(){
  if (top == -1){
    return true;
  }
  return false;
}

bool isFull(){
  if (top == size-1){
    return true;
  }
  return false;
}

void push(int x){
  if (isFull()){
    cout << "stack is full..." << endl;
  }
  else{
    top++;
    arr[top] = x;
  }
}

void pop(){
  if (isEmpty()){
    cout << "stack is empty..." << endl;
  }
  else{
    top--;
  }
}

void traverse(){
  if (isEmpty()){
    cout << "stack is empty..." << endl;
  }
  else{
    int i = 0;
    while (i <= top){
      cout << arr[i] << " ";
      i++;
    }
    cout << endl;
  }
}

void peek(int i){
  if(isEmpty()){
    cout << "stack is empty..." << endl;
  }
  else{
    cout << "Peeking at index "<<i<< " : "<< arr[i] <<endl;
  }
}

void topofstack(){
  if (isEmpty()){
    cout << "stack is empty..." << endl;
  }
  else{
    cout << "Top of stack is: " << arr[top] << endl;
  }
}

void bottomofstack(){
  if (isEmpty()){
    cout << "stack is empty..." << endl;
  }
  else{
    cout << "Bottom of stack is: " << arr[0] << endl;
  }
}



};

int main(){
  stack s(5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.traverse();
  s.topofstack();
  s.bottomofstack();
  
  s.pop();
  s.traverse();
  
  s.push(4);
  s.push(5);
  s.push(6);
  s.traverse();
  s.peek(4);
  
  s.push(7);
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.traverse();
  s.pop();
  s.pop();
}