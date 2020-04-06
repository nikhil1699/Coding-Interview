#include<bits/stdc++.h>
using namespace std;


void reverseArray(int arr[], int start, int end) 
{ 
    while (start < end) { 
        int temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    } 
} 
  
/* Function to left rotate arr[] of size n by d */
void leftRotate(int arr[], int d, int n) 
{ 
    if (d == 0) 
        return; 
    reverseArray(arr, 0, d - 1); 
    reverseArray(arr, d, n - 1); 
    reverseArray(arr, 0, n - 1); 
}
void printArray(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " "; 
} 
   
int main(){
    int n,d;
    cin>>n>>d;
    int myArray[n];
    for(int i=0;i<n;i++){
        cin>>myArray[i];
    }
    leftRotate(myArray,d,n);
    printArray(myArray,n);

}