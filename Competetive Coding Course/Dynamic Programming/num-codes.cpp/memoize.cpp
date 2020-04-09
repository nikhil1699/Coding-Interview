#include <bits/stdc++.h>
using namespace std;

int num_codes2(int* n, int size, int* arr){
    //Exponantial
    if(size==1){
        return 1;
    }
    if(size==0){
        return 1;
    }
    if(arr[size]>0){
        return arr[size];
    }

    int output=num_codes(n, size-1);
    if(output[size-2]*10 + output[size-1]<=26){
        output+= num_codes(n,size-2);
    }
    arr[size]=output;
    return output;
   
}

int main()
{
    int* arr=new int[1000];
    
    
    return 0;
}
