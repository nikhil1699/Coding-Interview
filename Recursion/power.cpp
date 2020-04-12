#include <bits/stdc++.h>
using namespace std;

int calculate_power(int x,int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }
    return x*calculate_power(x,n-1);
}



int main()
{
    int n,x;
    cin>>x>>n;
    cout<<calculate_power(x,n);
    
    
    return 0;
}
