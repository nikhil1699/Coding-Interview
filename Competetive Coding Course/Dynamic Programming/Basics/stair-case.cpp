
#include<bits/stdc++.h>
using namespace std;

long staircase(int n){
   
    long arr[n+1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for (long  i = 3; i <=n; i++)
    {
        long x=arr[i-1];
        long y=arr[i-2];
        long z=arr[i-3];
        if(i==3){
            arr[i]=4;
        }
        else{
            arr[i]=x+y+z;
        }
    }

    return arr[n];
}

int main(){
   cout<< staircase(4);
}