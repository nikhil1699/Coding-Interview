#include <bits/stdc++.h>
using namespace std;


void swapper(int* input, int i, int j){
    swap(input[i],input[j]);
}
void reverse(int * input, int start, int end){
    int i=start,j=end;
    while(i<j){
        swapper(input, i, j);
        i++;j--;
    }
}
void Rotate(int* input, int d, int n){
    if(d>=n){
        d=d%n;
    }
    reverse(input,0,n-1);
    reverse(input,0,n-d-1);
    reverse(input,n-d,n-1);
}

int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;
    
    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;

}
