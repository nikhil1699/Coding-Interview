#include <bits/stdc++.h>
using namespace std;

void permutationsHelper(string s, string sdash){
    if(s.size()==0){
        cout<<sdash<<" ";
    }
    else{
        for(int i=0;i<s.size();i++){
            string smallString= s.substr(0,i)+s.substr(i+1);
            permutationsHelper(smallString,sdash+s[i]);
        }

    }
    
}

void permutationsOfString(string s){
    permutationsHelper(s,"");
}

int main(){
    
    permutationsOfString("abcd");
    
    return 0;
}
