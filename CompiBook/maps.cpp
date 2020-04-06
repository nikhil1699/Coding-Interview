#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> m;
    m.insert(pair<int,int>(1,40));
    m.insert(pair<int,int>(2,50));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,60));
    m.insert(pair<int,int>(5,20));

    map<int,int> m2(m.begin(),m.end());
    map<int,int>::iterator it;
    for(it=m2.begin();it!=m2.end();++it){
        cout<<it->first<<"\t";
        cout<<it->second<<"\t";
    }  
     