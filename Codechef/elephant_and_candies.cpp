#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,c,n;
    cin>>t;

    while(t--){
        cin>>n>>c;
        int *A=new int[n];
        int sum=0;
        for(int i=0; i<n;i++){
            sum=sum+A[i];
        }
        if(sum<c){
            cout<<"No";
        }
        else{
            cout<<" Yes";
        }


    }
    return 0;
}