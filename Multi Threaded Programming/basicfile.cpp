#include<bits/stdc++.h>
#include<iostream>
#include<omp.h>
#define ll long long
using namespace std;
int main()
{

cout<<"Hello World from non threaded"<<endl;
omp_set_num_threads(20);
#pragma omp parallel
{
cout<<"Hello World from threaded"<<endl;
}
return 0;
}

