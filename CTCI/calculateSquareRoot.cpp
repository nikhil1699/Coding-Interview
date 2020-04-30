// Write a code to calculate the square root of a number
//n=100 10
//n=256 16

// Naive approach iterate through all numbers less than 100 and check if that number* itself is 100 
#include <bits/stdc++.h>
using namespace std;

int sqrt_helper(int n, int min, int max){
    if(min>max){
        return -1;
    }
    int any_number=(min+max)/2;
    if(any_number*any_number == n){
        return any_number;
    }
    else if(any_number*any_number<n){
        return sqrt_helper(n,any_number+1,max);
    }else{
        return sqrt_helper(n, min,any_number-1);
    }
}

int sqrt ( int n){
    return sqrt_helper(n,1,n);
}

int main(){
    
    cout<<sqrt(100);    
    
    return 0;
}


