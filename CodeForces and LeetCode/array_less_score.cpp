#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    
    cin>>n>>k;
    int arrayM[n];
    for(int i=0;i<n;i++){
        cin>>arrayM[i];
    }
    int count=0;
    int myVal=arrayM[k];
    for(int i=0;i<n;i++){
        if(arrayM[i]>=myVal){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}