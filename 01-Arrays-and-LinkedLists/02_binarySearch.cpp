#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int low = 0;
    int high = size;

    while (low <= high){
      int mid = (low+high)/2;
      if (key == arr[mid]){
        return mid;
      }
      else if (key < arr[mid]){
        high = mid - 1;
      }
      else{
        low = mid + 1;
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
  
  cout << binarySearch(arr, s, k);
  
}