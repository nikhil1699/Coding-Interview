#include<bits/stdc++.h>
using namespace std;
int reversDigits(int num) 
{ 
    int rev_num = 0; 
    while(num > 0) 
    { 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
    return rev_num; 
} 
int main(){
    int n;
    cin>>n;
    
    while(n--){
        int x;
        cin>>x;
        cout<<reversDigits(x)<<endl;
    }
    
    
}