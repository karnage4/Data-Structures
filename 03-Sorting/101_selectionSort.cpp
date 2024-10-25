#include<iostream>
using namespace std;


void selectionSort(int a[], int n){

    for(int i = 0 ; i<n ; i++){

      int min = i;

      for(int j=i+1; j<n; j++){
          if(a[j] < a[min]){
              min = j;
          }
      }

      swap(a[i], a[min]);
    }
}

void traverse(int a[], int n){
  
  for(int i=0; i<n; i++){
      cout << a[i] << " ";
  }
  cout << endl;
}

int main(){
  int a[] = {3,6,8,5,1};
  int n = 5;
  traverse(a,n);

  selectionSort(a,n);

  traverse(a, n);
  
  
}