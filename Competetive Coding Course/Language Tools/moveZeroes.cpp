#include <bits/stdc++.h>
using namespace std;

    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator it; 
  
        for(it=nums.begin();it != nums.end();it++){
            if(*it==0){
                nums.emplace_back(*it);
                nums.erase(it);
            }
        }
    
    }
int main()
{
    
    vector<int>x;
    x.push_back(0);
    x.push_back(3);
    x.push_back(11);
    x.push_back(0);
    x.push_back(1);
    x.push_back(0);
    moveZeroes(x);
    for(int i: x){
        cout<<i<<" ";
    }
    
    return 0;
}
