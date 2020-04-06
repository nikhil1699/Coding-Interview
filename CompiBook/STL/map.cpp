#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int, int> A;
	A[1]=100;
	A[2]=200;
	A[4]=500;
	A[20]=600;
	cout<<A[4]<<" "<<A[20]<<endl;

	map<char,int> cnt;
	string s="Hello World I am a doofus";
	for(char c: s){
		cout<<c<<" "<<cnt[c]<<endl;
		cnt[c]++;
		
	}
	cout<<cnt['a']<<" "<<cnt['o']<<" "<<cnt['l']<<endl;
	cout<<endl;
	for(char d: s){
		cout<<d<<" "<<cnt[d]<<endl;
	}
	cout<<endl;
	cout<<cnt['a']<<" "<<cnt['o']<<" "<<cnt['l']<<endl;

	auto it1=cnt.find('l');
	cout<<"Found"<<endl;
	auto it2=cnt.find('z');
	if(it2==cnt.end()){
		cout<<"Not Found"<<endl;
	}else{
		cout<<"Found"<<endl;
	}

	cnt.erase('H');

	for(char d: s){
		cout<<d<<" "<<cnt[d]<<endl;
	}


	return 0;
}

unordered_map<int,int> freq;
for(int i=1;i<size;i++)
		arr[i]+=arr[i-1];
int m=0;
for(int i=0;i<size;i++){
	if(arr[i]==0){
		if(m<i+1) m=i+1;
	}
	else if(freq.count(arr[i])>0){
		if(m<i-freq[arr[i]]) m=i-freq[arr[i]];
	}
	else freq[arr[i]]=i;
}
return m;


