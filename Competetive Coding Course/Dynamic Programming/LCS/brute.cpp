#include <bits/stdc++.h>
using namespace std;
 
// We have two strings S and T
// return length of longest common subsequence. Subsequence means just order maintain, nt necessarily consecutive

int lcs(string s, string t){
    //Base Case

    if(s.empty() || t.empty()){
        return 0;
    }

    if(s[0]==t[0]){
        return 1 + lcs(s.substr(1),t.substr(1));
    }

    else{
         //Recursive calls
        int a=lcs(s.substr(1),t);
        int b=lcs(s,t.substr(1));
        int c=lcs(s.substr(1),t.substr(1));
        return max(a,max(b,c));

    }
   
}

int main(){
    
    string s,t;
    cin>>s>>t;
    cout<<lcs(s,t)<<endl;

    return 0;
}
