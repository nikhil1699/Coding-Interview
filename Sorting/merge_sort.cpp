#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;


void merge(int a[], int si, int ei){

				int size=ei-si+1;
				int mid=(si+ei)/2;
				//Create a dynamic array in heap
				int * out=new int [size];
				int i=si;
				int j=mid+1;
				int k=0;
				while(i<=mid && j<=ei){
				if(a[i]<a[j]){
				
								out[k]=a[i];
								i++;k++;
				}
				else{
				
								out[k]=a[j];
								j++;k++;
								
				}
				}
				while(i<=mid){
				
								out[k]=a[i];
								k++;i++;
				}
				while(j<=ei){
				
								out[k]=a[j];
								k++;j++;

				}
				int m=0;
				for(int i=si;i<=ei;i++){
				
								a[i]=out[m];
								m++;
				}
				delete []out;

}
void mergeSort(int a[], int si, int ei){

				if(si>=ei){
								return;
				}
				int mid=(si+ei)/2;
				mergeSort(a,si,mid);
				mergeSort(a,mid+1,ei);
				merge(a,si,ei);
}

int main()
{
int a[]={6,5,4,3,2,1};
mergeSort(a,0,5);
for(int i=0;i<=5;i++){

				cout<<a[i]<<" ";
}


return 0;
}

