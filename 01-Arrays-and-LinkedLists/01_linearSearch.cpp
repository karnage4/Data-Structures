#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int key){

  for (int i = 0; i<size ; i++){
    if (arr[i]==key){
      return i;
    }
  }
  return -1;
}

int main(){
  int s, k;
  cout << "enter size of array: ";
  cin>>s;
  cout<<endl;
  int arr[s];
  
  cout <<"enter elements of array:";

  for (int i=0; i<s; i++){
    cin >> arr[i] ;
    
  }

  cout <<"enter key to find: ";
  cin >>k;
  cout << endl;
  
  cout << linearSearch(arr, s, k);
  
}