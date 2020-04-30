#include <bits/stdc++.h>
using namespace std;

/*
Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far

*/

int maxSumSubarray(vector<int> v){
    int max_so_far = INT_MIN, max_ending_here = 0,start = 0, end = 0, s=0;
    for (int i = 0; i < v.size(); i++){
        max_ending_here += v[i];
        if(max_so_far < max_ending_here){
            max_so_far = max_ending_here ;
            start = s;
            end = i;
        }
        if(max_ending_here < 0){
            max_ending_here = 0;
            s = i+1 ;
        }
    }
    cout<< max_so_far<<endl;
    cout<<" Start = "<<start<< " end = "<<end;
   return 0;
}

int main(){
    vector<int> v= {5,2,-100,-2,9,20,0,1,-10};
    maxSumSubarray(v);
    
    
    return 0;
}

int n;
string name;
long num;
cin >> n;
cin.ignore();
map <string, long> pBook;
for (int i = 0; i < n; i++) {
    cin >> name;
    cin >> num;
    pBook[name] = num;
}
while(cin >> name) {
    if (pBook.find(name) != pBook.end()) {
        cout << name << "=" << pBook.find(name)->second << endl;
    } else {
        cout << "Not found" << endl;
    }
}

