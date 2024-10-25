#include<iostream>
#include<vector>
using namespace std;

//commented statements cannot be applied in stack using resizable arrays

class stack{
public:
vector<int> arr;
int top;

stack(){
  top = -1;
}

// bool isEmpty(){
//   if (top == -1){
//     return true;
//   }
//   return false;
// }

// bool isFull(){
//   if (top == arr.size()-1){
//     return true;
//   }
//   return false;
// }

void push(int x){
  // if (isFull()){
  //   cout << "Stack is full...";
  // }
  // else{
    arr.push_back(x);
    top++;
  // }
}

void pop(){
  if (top==-1){
    cout << "Stack is empty...";
  }
  else{
    arr.pop_back();
    top--;
  }
}

void traversal(){
  if (top==-1){
    cout << "Stack is empty...";
  }
  else{
    for (int i = 0; i<arr.size(); i++){
      cout << arr[i] << " ";
    }
  }
  cout << endl;
}

void topofstack(){
  if (top==-1){
    cout << "Stack is empty...";
  }
  else{
    cout << "top of stack is: " << arr[top] << endl;
  }
}
};

int main(){
  stack s;
  s.push(2);
  s.push(4);
  s.push(5);
  s.push(7);
  s.traversal();
  s.topofstack();

  s.pop();
  s.pop();
  s.traversal();

  s.pop();
  s.pop();

  s.pop(); //stack has reached its lower bound so cant go below further.

  
}