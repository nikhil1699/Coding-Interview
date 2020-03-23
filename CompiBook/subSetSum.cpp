//sort nlogn 
//Find sum of all elements of a set
//Maintain a run_sum
// for each runsum, remaining couterpart is sum-runsum
//n2
// 1->21
// 5->17
// 11->11
// 5->17

//currently we have v=1,5,5,11 and s=21,17,11,17


#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int> v={1,11,5,5};
set<int> currset;
int sum=0;
int n;
cin>>n;
bool flag=false;
for(int i=0;i<n;i++){
    sum=sum+v[i];
    //O(n)
}
for(int i=0;i<n;i++){
    currset.insert(sum-v[i]);
}
sort(v.begin(),v.end());
int runsum=0;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    runsum=v[i];
       if (currset.find(runsum) != currset.end()){
           flag=true;
       }
       else{
           runsum=runsum+v[j];
       }
    }

}
  cout<<flag<<endl; 
return 0;
}