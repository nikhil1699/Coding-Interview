#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int> s;
	s.insert(-1);s.insert(3);s.insert(3);s.insert(12);s.insert(5);s.insert(11);

	cout<<"Printing elements of set "<<endl;
	for(int x: s){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<"Updater loop"<<endl;
	for(int y: s){
		y++;
		cout<<y<<" ";
	}	
	cout<<endl;

	auto it1=s.find(3);
	if(it1==s.end()){
		cout<<"Not Found in set"<<endl;
	}
	else{
	cout<< *it1<<endl;
	}

	auto it2=s.lower_bound(3);
	auto it3=s.upper_bound(3);
	cout<<*it3<<endl;
	cout<<*it2<<endl;

	auto it4=s.upper_bound(12);
	if(it4==s.end()){
		cout<<"Upper Bound Not possible"<<endl;
	}
	else{
		cout<<*it4<<endl;
	}
	return 0;
}
