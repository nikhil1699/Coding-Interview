#include<bits/stdc++.h>
using namespace std;

int main(){
    //Write your code here
    int n;
    cin>>n;
    vector<int> donuts;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        donuts.push_back(m);
    }
    int sum=0;
    sort(donuts.begin(),donuts.end(),greater<>());
    for(int i=0;i<n;i++){
        sum+=donuts[i]*(pow(2,i));
    }
    cout<<sum;

    return 0;

}