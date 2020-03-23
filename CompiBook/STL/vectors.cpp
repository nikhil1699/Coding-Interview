#include<bits/stdc++.h>
using namespace std;

bool f(int x, int y){
	return x>y;
}

int main(){
vector<int> v={11,2,13,4,5,32,2,1,7};
sort(v.begin(), v.end());
bool isPresent=binary_search(v.begin(),v.end(),4);
v.push_back(100);
v.push_back(100);
v.push_back(100);
v.push_back(100);
v.push_back(125);
v.insert(v.begin(),0);
auto it1=lower_bound(v.begin(), v.end(),100);
auto it2=upper_bound(v.begin(), v.end(),100);
cout<< *it1<<" "<< *it2<<endl;
cout<<it2-it1<<" This is the number of occurances of 100"<<endl;
for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
{
	
	cout<< *i<<" ";
}
cout<<endl;
sort(v.begin(), v.end(),f);
cout<<"Printing using std::vector iterator synatx "<<endl;
for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
{
	
	cout<< *i<<" ";
}
cout<<endl;
cout<<"Printing using new for loop "<<endl;
for(int x: v){
	
	cout<<x<<" ";
}
cout<<endl;

cout<<"Printing from updater for loop with ampercent "<<endl;
for(int &y: v){
	
	y++;
	cout<<y<<" ";
}

	
	return 0;
}