#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int one_counter=0;
    int zero_counter=0;
    for(int i=0;i<n;i++){
       
        if(arr[i]==1){  
           if(arr[i+1]==0){
               zero_counter++;
           }
           if(arr[i+2]==0){
               zero_counter++;
           }
           if(arr[i+3]==0){
               zero_counter++;
           }
           if(arr[i+4]==0){
               zero_counter++;
           }
           if(arr[i+5]==0){
               zero_counter++;
           }
        }
    }
    cout<<zero_counter;
    
    
    return 0;
}
