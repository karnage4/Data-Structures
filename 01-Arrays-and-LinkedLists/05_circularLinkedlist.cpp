#include<iostream>
using namespace std;

//creation
class node{
public:
    int data;
    node* next;

};

//traversal
void circularLLtraversal(node* head){
    node* ptr = head;
    do{
        cout << ptr->data;
        ptr = ptr->next;
        cout << endl;
        
    } while(ptr!=head);  //so it doesnt get missed thats why end mein condition lagayi he
}

//insertion
node* insertAtfirst(node* head, int value){
    node* ptr = new node();  // jo naya node insert karana he
    ptr->data = value;

    node* current = head->next; //head se traverse karayenge head ke aik peeche tak taake wahan se naya node insert ho as its circular
    while(current->next != head){

        current = current->next;
        
    }
    current->next = ptr;
    ptr->next = head;
    head = ptr;  //new inserted node ab apka first node hoga toh usko head banadenge

    return head;
}

int main(){
  node* head = new node();
  node* second = new node();
  node* third = new node();
  node* fourth = new node();

  head->data = 4;
  head->next = second;

  second->data = 3;
  second->next = third;

  third->data = 6;
  third->next = fourth;

  fourth->data = 1;
  fourth->next = head;

  circularLLtraversal(head);
  cout << endl;

  head = insertAtfirst(head, 15);
  head = insertAtfirst(head, 60);
  circularLLtraversal(head);
  cout << endl;
    
}