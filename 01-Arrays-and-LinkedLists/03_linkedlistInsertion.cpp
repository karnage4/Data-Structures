#include<iostream>
using namespace std;

//creation
class node{
public:
int data;
node* next;

node(){
  data= 0;
  next = NULL;
}

};

//traversal
void linkedlistTraversal(node* ptr){
  while(ptr != NULL){
    cout << ptr->data << endl;
    ptr = ptr->next;
  }
}

node* insertAtBeginning(node* head, int data){ //takes in head of a LL and works on it
  node* ptr = new node();
  ptr->next = head;
  ptr->data = data;

  return ptr; // returns new head 
}

node* insertAtBetweenIndex(node* head, int index, int data){//also taking index as where to insert the new node
  
  node* ptr = new node();
  node* current = head;
  int i = 0;

  while(i!=index-1){ //insert karne wali jaga se aik pehle
    current = current->next;
    i++;
  }
  ptr->data = data;
  ptr->next = current->next;
  current->next = ptr;

  return head; //returning head after making changes to the LL
  
}


node* insertAtEnd(node* head, int data){
  node* ptr = new node();
  node* current = head;
  ptr->data = data;

  while(current->next!=NULL){ //increment current ptr jab tak wo last node pe na ponch jaye
    current = current->next;
  }
  current->next = ptr;
  ptr->next = NULL;

  return head;
}


node* insertAfterNode(node* head, node* prevnode, int data){ //node will be given jiske aage insert karna he
  
  node* ptr = new node();
  ptr->data = data;

  ptr->next = prevnode->next;
  prevnode->next = ptr;

  return head; 
}


int main(){
  node* head = new node();
  node* second = new node();
  node* third = new node();

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  linkedlistTraversal(head);
  cout << endl;

  head = insertAtBeginning(head, 56); //updating the head as new head will be returned
  linkedlistTraversal(head); //traversing thru LL with new head
  cout << endl;

  head = insertAtBetweenIndex(head,2, 70);
  linkedlistTraversal(head); //traversing thri LL with changes
  cout << endl;

  head = insertAtEnd(head,100);
  linkedlistTraversal(head);
  cout << endl;

  //head = insertAfterNode(head,second,85); //original second node i.e 1 2 3 ke baad 1 2 85 3 hoga
  linkedlistTraversal(head);
  cout << endl;

  
}