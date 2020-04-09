#include <bits/stdc++.h>
using namespace std;

int countStepsToOne(int n){
    if(n<=1){
        return 0;
    }
    int a=countStepsToOne(n-1);
    int b=INT_MAX;
    int c=INT_MAX;

    if(n%2 == 0){
        b=countStepsToOne(n/2);
    }
    if(n%3 == 0){
        c=countStepsToOne(n/3);
    }
    return min(a,min(b,c))+1;
}

int main()
{
    int n;
    cin>>n;
    cout<<countStepsToOne(n)<<endl;
    
    
    return 0;
}
