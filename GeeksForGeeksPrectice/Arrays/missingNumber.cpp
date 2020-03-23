#include<bits/stdc++.h>
using namespace std;

int findMissingElement(vector<int> v,int n){
    int numsum=(n*(n+1))/2;
    int newsum=0;
    for(auto x:v){
        newsum=newsum+x;
    }
    if(numsum-newsum>0){
        return (numsum-newsum);
    }
    return 0;
}
int main(){
   
    vector<int> C={1,2,3,5};//N=5
    vector<int> D={1,2,3,4,5,6,7,8,9,10,11,13,14};//N=14
    vector<int> E={2,3,4,5,6,7,8};//N=8
    vector<int> F={1,2,3,4,5,6,7};//N=8
    cout<<findMissingElement(C,5)<<endl;
    cout<<findMissingElement(D,14)<<endl;
    cout<<findMissingElement(E,8)<<endl;
    cout<<findMissingElement(F,8)<<endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int findMissingElement(vector<int> v,int n){
//     int numsum=(n*(n+1))/2;
//     int newsum=0;
//     for(auto x:v){
//         newsum=newsum+x;
//     }
//     if(numsum-newsum>0){
//         return (numsum-newsum);
//     }
//     return 0;
// }


// int main() {
// 	//code
// 	vector<int>C;
// 	int T,N;
// 	cin>>T;
// 	while(T--){
	    
// 	    cin>>N;
// 	    for(int i=0;i<N-1;i++){
// 	        cin>>C[i];
// 	    }
// 	    findMissingElement(C,N);
// 	}
// 	return 0;
// }