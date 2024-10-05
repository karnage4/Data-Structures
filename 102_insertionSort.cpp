#include<iostream>
using namespace std;


void insertionSort(int* arr, int n){
  //first pass
  for ( int i=1; i<=n-1; i++){
    //second pass
    for(int j=i; j>0; j--){
      
      if(arr[j] < arr[j-1]){
        swap( arr[j], arr[j-1] );
      }
      else{
        break;
      }
    }
    
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
  insertionSort(a,n);
  traverse(a,n);
  
}