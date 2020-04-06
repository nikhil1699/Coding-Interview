#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string stringArray[n];
    for(int i=0;i<n;i++){
        cin>>stringArray[i];
    }

    int q;
    cin>>q;
    vector<int>result;

    string queryArray[q];
    for(int i=0;i<q;i++){
        cin>>queryArray[i];
    }
    for(int i=0;i<q;i++){
        int myCount=count(stringArray,stringArray+n,queryArray[i]);
        result.push_back(myCount);
    }
    for(int i=0;i<q;i++){
        cout<<result[i]<<endl;
    }
}