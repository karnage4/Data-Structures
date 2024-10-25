#include<iostream>
using namespace std;

//creation 
class node{
public:
  node* prev;
  int data;
  node* next;
};

//forward traversal
void forwardTraversal(node* head){
  node* current = head;

  while(current->next != NULL){
    cout << current->data << endl;
    current = current->next;
  }
  cout << current->data << endl;

}

//backward traversal
void backwardTraversal(node* head){
  node* current = head;

  while(current->prev != NULL){
    cout << current->data << endl;
    current = current->prev;
  }
  cout << current->data << endl;
  
}


int main(){

  node* N1 = new node();
  node* N2 = new node();
  node* N3 = new node();
  node* N4 = new node();

  N1->prev = NULL;
  N1->data = 23;
  N1->next = N2;

  N2->prev = N1;
  N2->data = 34;
  N2->next = N3;

  N3->prev = N2;
  N3->data = 56;
  N3->next = N4;

  N4->prev = N3;
  N4->data = 77;
  N4->next = NULL;

  forwardTraversal(N1); //in this the head is the first node
  cout << endl;

  backwardTraversal(N4); //in this the head is the last node
  cout << endl;

  
}