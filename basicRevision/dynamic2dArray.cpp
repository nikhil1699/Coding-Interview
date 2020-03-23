#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
int main()
{
				int m,n;
cin>>m;
cin>>n;
int** p= new int* [m];
for(int i=0;i<m;i++){

				p[i]=new int[n];
				for(int j=0;j<n;j++){
				cin>>p[i][j];
				}
}

for(int i=0; i<m;i++){
delete[] p[i];
}
delete[] p;
cout<<"Array Deleted";
return 0;
}

