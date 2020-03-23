#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;

bool isSorted(int a[], int size){
if(size==0 || size==1){
return true;
}
if(a[0]>a[1]){
return false;
}
bool isSmallerSorted=isSorted(a+1,size-1);
return isSmallerSorted;
}


int main()

{
	int a[]={1,2,4,5,6};
	cout<<isSorted(a,5);


return 0;

}

