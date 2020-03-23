#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;

template<class T>
T maxi(T x,T y){

				if(x>y){
				return x;
				}
				else
								return y;
}

int main()
{
cout<<maxi(4,5)<<endl;
cout<<maxi(4.54,5.66);
return 0;
}

