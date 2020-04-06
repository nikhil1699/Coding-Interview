#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,x,n;
    set<int> s1;
    cin>>t;
    while(t--){
        cin>>n>>x;
        int value;
        for(int i=0;i<n;i++){
            cin>>value;
            s1.insert(value);
        }
        
        int ans;
        vector<int>s2;
       for(auto y:s1){
           if(y!=(y-1)){
               s2.push_back(y);
           }
       }


    }

    return 0;
}