typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
 comparator(vector<pair<int,int>> vect){
    return
}
int main()
{
    //Write your code here
    vector<pair<ll,ll>> myVect;
    int n;
    
    cin>>n;
    for(int i=0;i<n;i++){
    	int m, n;
        cin>>m>>n;
        myVect.push_back(make_pair(m,n));  
    }
    sort(myVect.begin(),myVect.end());
    return 0;
}