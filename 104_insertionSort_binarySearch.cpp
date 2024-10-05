#include<iostream>
using namespace std;

int binarySearch(int* a, int low, int high, int key){

  //if one element in array
  if (low==high){
    return low;
  }

  int mid = low + ((high-low)/2);

  if (key < a[mid]){
    return binarySearch(a, low, mid, key);
  }
  else if (key > a[mid]){
    return binarySearch(a, mid+1, high, key);
  }

  //this is the insert position where key will be inserted
  return mid;
  
}


void binaryInsertionSort(int* a, int n){
  int pos, i , j;
  int key;

  for(i = 1; i<n; i++){
    pos = binarySearch(a, 0, i-1, a[i]); //finding final position for the key
    key = a[i];

    for (j = i-1; j>= pos; j--){ //we will be decrementing j until it reaches pos position to insert the key
      a[j+1] = a[j];
      
    }
    a[pos] = key; 
  }
}

void traverse(int* arr, int n){
  for (int i=0; i<n; i++){
      cout << arr[i] << " ";

  }
  cout << endl;
}

int main(){
  int a[] = {7,6,5,4,3,2,1,0};
  int n = 8;
  binaryInsertionSort(a,n);
  traverse(a,n);
}