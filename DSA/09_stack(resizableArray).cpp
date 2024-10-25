#include<iostream>
using namespace std;

class RAstack{
  private:
int* stackarray;
int size;
int top;

void resize(int newsize){
  int* newarray = new int[newsize];

  for(int i=0; i < newsize; i++){
    newarray[i] = stackarray[i];
  }
  delete [] stackarray;
  stackarray = newarray;
  size = newsize;
}

public:
RAstack(){
  size = 2;
  top = -1;
  stackarray = new int[size];
}

~RAstack(){
  delete[] stackarray;
}

bool isempty() {
  return top == -1;
}

void push(int x){
  if ( top == size - 1){
    resize(2 * size);
  }
  stackarray[++top] = x;
}

void pop(){
  if (isempty()){
    cout << "stack is empty...";
  }

  int item = stackarray[top--];

  if (top > -1 && top + 1 == size/4){
    resize(size/2);
  }
  cout << "popped item is "<<item<<endl;
}

void stacksize(){
  cout << size << endl;
}

void traversal(){
  for (int i=0; i<top+1;i++){
    cout << stackarray[i] << " ";
  }
  cout << endl;
}
};

int main(){
  RAstack s;
  s.push(30);
  s.push(50);
  s.push(70);
  s.push(85);
  s.traversal();

  s.stacksize(); // 4/4 is used, another push and cap will go to 8
  s.push(99);
  s.traversal();
  s.stacksize(); // 5/8 cap is used 

  s.pop();
  s.pop();
  s.pop();
  s.stacksize();
  s.pop();
  s.traversal();
  s.stacksize();
  
}