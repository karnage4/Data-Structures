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

//Delete at the beginning
node* Deletefirst(node* head){
    node* ptr = head;
    head = head->next;
    delete(ptr);

    return head; //returning the new head after deleting first node of the list
}


//Delete at given index
node* DeleteAtIndex(node* head, int index){
    node* current = head;
    node* p = new node();
    int i = 0;

    while(i != index - 1){
        current = current->next;
        i++;
    }

    p = current->next;
    current->next = p->next;
    delete(p);

    return head;
}

//Delete the last node
node* Deletelastnode(node* head){
    node* current = head;
    node* p = head->next;

    while(p->next != NULL){
        current = current->next;
        p = p->next;
    }
    current->next = NULL;
    delete(p);

    return head;
}

//Delete node at given value
node* DeleteAtValue(node* head, int value){
    node* current = head;
    node* p = head->next;

    while(p->data != value && p->next != NULL){ //traverse until value mil jaye deletion wale pointer pe ya phir deletion wale pointer ke aage NULL na ajaye
        current = current->next;
        p = p->next;
    }
    
    current->next = p->next;
    delete(p);

    return head;
}

int main(){
  node* head = new node();
  node* second = new node();
  node* third = new node();
  node* fourth = new node();
  node* fifth = new node();
  node* sixth = new node();

  head->data = 4;
  head->next = second;

  second->data = 3;
  second->next = third;

  third->data = 8;
  third->next = fourth;

  fourth->data = 1;
  fourth->next = fifth;

  fifth->data = 7;
  fifth->next = sixth;

  sixth->data = 2;
  sixth->next = NULL;

  linkedlistTraversal(head);
  cout << endl;

  head = Deletefirst(head);
  linkedlistTraversal(head);
  cout << endl;


  head = DeleteAtIndex(head,2);
  linkedlistTraversal(head);
  cout << endl;

  head = Deletelastnode(head);
  linkedlistTraversal(head);
  cout << endl;

  head = DeleteAtValue(head, 8);
  linkedlistTraversal(head);
  cout << endl;
    


}