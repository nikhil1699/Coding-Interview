#include <bits/stdc++.h>
using namespace std;

int num_code(int* arr, int size){
    // arr[i] is what are the possible codes if you consider first i digits of the input array
    int* output=new int[size+1];
    output[0]=1;
    output[1]=1;

    for(int i=2;i<=size;i++){
        output[i]=output[i-1];
        if(input[i-2]*10 + input[i-1]<=26){
        output[i]+=output[i-2];
        }
    }
    int ans=output[size];
    delete[] output;
    return ans;
}

int main()
{
    
    
    
    return 0;
}
