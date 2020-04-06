#include<bits/stdc++.h>
using namespace std;
vector<int>  kSmallest(int input[], int n, int k){
    priority_queue<int>pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    for(int i=k;i<n;i++){
        if(input[i]<pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main(){
    int input[]={2,12,9,16,10,5,3,20,35,11,1,8,6};
    int k=5;
    int n=13;
    vector<int> op=kSmallest(input,n,k);
    for(int x: op){
        cout<<x;
    }

    return 0;

}