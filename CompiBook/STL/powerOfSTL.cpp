#include<bits/stdc++.h>
using namespace std;
int main(){
		
	set<pair<int, int>> s;
	s.insert({10,20});
	s.insert({2,3});
	s.insert({30,400});
	s.insert({401,500});
	int point;
	cin>>point;
	auto it=s.upper_bound({point,INT_MAX});
	if(it==s.begin()){
		return -1;
	}else{
	it--;
	}
	pair<int, int> current= *it;
	if(current.first<=point && point<=current.second){
		cout<<"Yes "<<current.first<<","<<current.second<<endl;
	}
	else{
		cout<<"Not in any interval"<<endl;
	}

	return 0;
}