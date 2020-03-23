#include<bits/stdc++.h>

using namespace std;

int main(){
	
	vector<int>* vp=new vector<int>();//Dynamic memory wala vector
	vector<int> v;
	v.push_back(10);//10
	v.push_back(20);//10,20
	v.push_back(30);//10,20,30
	//v[0] gives 10
	//v[1]=100; changes second element to 100
	for (int i = 0; i < v.size(); ++i)
	{
		/* code */
		cout<<v[i];
	}

	v.pop_back();//Removes last element


	return 0;
}