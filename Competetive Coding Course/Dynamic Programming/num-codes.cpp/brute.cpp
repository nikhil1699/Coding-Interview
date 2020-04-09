#include <bits/stdc++.h>
using namespace std;

int num_codes(int* n, int size){
    //Exponantial
    if(size==1){
        return 1;
    }
    if(size==0){
        return 1;
    }
    int output=num_codes(n, size-1);
    if(output[size-2]*10 + output[size-1]<=26){
        output+= num_codes(n,size-2);
    }
    return output;
   
}

int main()
{
    
    
    
    return 0;
}
