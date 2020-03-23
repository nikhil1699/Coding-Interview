#include<bits/stdc++.h>
#include<iostream>
#include<omp.h>
#define ARRAY_SIZE 10
#define NUM_THREADS 4
using namespace std;
int j;
int main(int argc,char* argv[])
{

				int n_per_thread;
				int total_thread=NUM_THREADS;
int a[]={1,2,3,4,5,6,7,8,9,10}; int b[]={10,9,8,7,6,5,4,3,2,1};int c[10];

//Parrallelisation happens inside the for loop

for(int i=0;i<10;i++){

				a[i]=i;
}

for(int j=0;j<10;j++){

				b[j]=j;
}
omp_set_num_threads(total_thread);
n_per_thread=10/total_thread;/home/nikhil
#pragma omp parallel for private(j) schedule(dynamic,n_per_thread)
for(int j=0;j<10;j++){

				c[j]=a[j]+b[j];
				cout<<"Thread "<<omp_get_thread_num()<< " works on element "<<j<<" "; 
				cout<<" "<<c[j]<<endl;
}


return 0;
}

