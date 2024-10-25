#include<iostream>
using namespace std;


void insertionSort_halfexchanges(int* a, int n){

  //loop for passes
  for(int i=1; i<n; i++){

    int key = a[i];
    int j;

    //loop for each pass
    for(j = i-1; j>=0 && a[j] > key; j--){

      a[j+1] = a[j];
    }
    a[j+1] = key;
  }
}
void traverse(int* arr, int n){
  for (int i=0; i<n; i++){
      cout << arr[i] << " ";
    
  }
  cout << endl;
}

int main(){
  int a[] = {3,2,1,0};
  int n = 4;
  insertionSort_halfexchanges(a,n);
  traverse(a,n);
  
}