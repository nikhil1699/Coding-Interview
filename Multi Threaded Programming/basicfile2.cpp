#include<bits/stdc++.h>
#include<iostream>
#include<omp.h> 
using namespace std; 
int main(int argc,char*argv[]) 
{ 
   
  cout<<"Welcome from non threaded"<<endl; 
  omp_set_num_threads(20); 
  #pragma omp parallel 
  { 
  int th_id,nthreads; 
  th_id=omp_get_thread_num(); 
  nthreads=omp_get_num_threads(); 
  cout<<"Hello World from thread "<<th_id<<"   of   "<<nthreads<<endl; 
  } 
  return 0; 
 } 

