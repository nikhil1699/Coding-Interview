#include<bits/stdc++.h>
using namespace std;

void showq(priority_queue<int>q){
    priority_queue<int> g=q;
    while(!g.empty()){
        cout<<"\t"<<g.top();
        g.pop();
    }
    cout<<endl;
}
void showpqm( priority_queue<int,vector<int>,greater<int>>pqm){
     priority_queue<int,vector<int>,greater<int>> g=pqm;
    while(!g.empty()){
        cout<<"\t"<<g.top();
        g.pop();
    }
    cout<<endl;
}
int main(){
    priority_queue<int> pq;
    pq.push(13);pq.push(12);pq.push(2);pq.push(24);
    cout<<"Show initial max heap "<<endl;
    showq(pq);
    cout<<endl;
    cout<<pq.size()<<endl;
    cout<<"***********Min heap***********"<<endl;
    priority_queue<int,vector<int>,greater<int>>pqmin;
     pqmin.push(13);pqmin.push(12);pqmin.push(2);pqmin.push(24);
    cout<<"Show initial min heap "<<endl;
    showpqm(pqmin);
    cout<<endl;
    cout<<pqmin.size()<<endl;
    cout<<"*************************"<<endl;
    vector<int> v={1,5,2,3,7,6,4,11};
    make_heap(v.begin(), v.end());
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;

    v.push_back(22);
    push_heap(v.begin(),v.end());

    pop_heap(v.begin(), v.end()); 
    v.pop_back(); 
    for(int y:v){
        cout<<y<<" ";
    }
    cout<<endl;



    return 0;
}