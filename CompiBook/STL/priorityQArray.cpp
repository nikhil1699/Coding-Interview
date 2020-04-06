// We have a k sorted array , We have to sort the array in decreasing order

//Suppoe k=3, input array ka har element index i se yaa to k-1 positions left ya k-1 positions right jaa sakta hai
//10 12 15 6 9
//15 12 10 9 6
#include<bits/stdc++.h>
using namespace std;

bool checkMinHeap(int arr[], int n){
    for(int i=0;i<nli++){
        if((2*i+1)<n && arr[i]<arr[2*i+1]){
            return false;
        }
        if((2*i+2)<n && arr[i]<arr[2*i+2]){
            return false;
        }
        
    }
    return true;
}

void ksortedArray(int input[], int n, int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){
        input[j]=pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while(! pq.empty()){
        input[j]=pq.top();
        pq.pop();
    }
}

int main(){
    int input[]={10,12,6,7,9};
    int k=3;
    ksortedArray(input,5,k);
    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }
    return 0;

}