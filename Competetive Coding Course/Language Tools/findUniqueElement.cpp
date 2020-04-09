#include<bits/stdc++.h>
using namespace std;

int FindUnique(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
map<int,int> m;
  for(int i = 0;i<size;i++){
    m[arr[i]] = 0;
  }
  for(int i = 0;i<size;i++){
    m[arr[i]]+=1;
  }
  map<int,int> :: iterator it;
  for(it = m.begin();it!=m.end();it++){
    if((*it).second==1){
      return (*it).first;
    }
  }
  
}


int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindUnique(input,size)<<endl;
		
	return 0;
}
