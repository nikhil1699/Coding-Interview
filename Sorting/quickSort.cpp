#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;

int partation(int input[],int start,int end){
				int pivot=input[start];
				int count=0;
				for(int i=start+1;i<=end;i++){
				
							if(input[i]<=pivot){
							
											count++;
							}

				}
							int pivotIndex=start+count;
							int temp=input[start];
							input[start]=input[pivotIndex];
							input[pivotIndex]=temp;

							//Shifting the elements according to their value W.R.T pivot	
							int i=start; int j=end;
							while(i<=pivotIndex && j>=pivotIndex){
							
											while(input[i]<=pivot){
											i++;
											}

											while(input[j]>pivot){
											j--;
											}

											if(i<pivotIndex && j>pivotIndex){
											
															int temp=input[i];
															input[i]=input[j];
															input[j]=temp;
															i++;j--;
											}

							}
							return pivotIndex;
				
}





void quickSortHelper(int input[],int start,int end){

				if(start >= end){
				
								return;
				}
				int pivotIndex=partation(input,start,end);
				quickSortHelper(input, start,pivotIndex-1);
				quickSortHelper(input,pivotIndex+1,end);
}
void quickSort(int input[],int n){
		
				quickSortHelper(input,0,n-1);
}


int main()
{

	int array[]={2,3,4,1,5,4,2,1,7,2,3,2,1,6,7,8,1,2,3,4,9,0};
	quickSort(array,22);
	for(int i=0; i<22;i++){
	cout<<array[i]<<" ";
	}

return 0;
}

