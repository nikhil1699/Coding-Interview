#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }    
    int sum1;
    int sum2;
    int me=*(max_element(v.begin(),v.end()));
    for(int i=1;i<=me;i++){
        sum1=sum1+i;
    }
    for(int i=0;i<n;i++){
        sum2=sum2+v[i];
    }
    cout<<"Required duplicate is "<<sum2-sum1;
    
    
    return 0;
}
