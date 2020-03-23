#include<bits/stdc++.h>
using namespace std;
int main(){
	
	//taking space separated numbers as input
	int a,b;
	string x;
	cin>>a>>b>>x;
	//123 456 monkey as well as
	// 123 456
	// monkey

	//Reading Whole Line from input
	string s;
	getline(cin, s);


//  If amount of data input is unknown
//  This loop reads elements from the input one after another, until there is no more
//	data available in the input.
	while (cin >> x) {
		// code
	}


// Huge Numbers
	long long x = 123456789123456789;
	


	/*

( a + b ) mod m = ( a mod m + b mod m ) mod m
( a − b ) mod m = ( a mod m − b mod m ) mod m
( a · b ) mod m = ( a mod m · b mod m ) mod m

Always take modulo before these three operations

	*/



	//Comparision of floating Point numbers can be inaccurate if use == operator, here's a better way 1e is epsilon ie, 10^-9
	if (abs(a-b) < 1e-9) {
	// a and b are equal
	}

	// How to shorten code
	typedef long long ll;
	// After this long long a can be written ll a;

	//Macros
	#define F first
	#define PB push_back
	/*
	v.push_back(first) => v.PB(F)
	*/
	
	// Sum of an AP: a+......+b=(n/2)*(a+b)
	// Sum of GP a+ak^2+ak^3......+b= (b*k-a)/(k-1)

	

	/*    SET THEORY
	A = {1, 2, 5} and B = {2, 4}, then A ∩ B = {2}
	A = {3, 7} and B = {2, 3, 8}, then A ∪ B = {2, 3, 7, 8}.
	A = {2, 3, 7, 8} and B = {3, 5, 8}, then A \ B = {2, 7}.

	A set S with n elements has 2^n subsets including null set
	find Fibonacci number in O(1) f(n)=[(1+sqrt(5))^n - (1-sqrt(5))^n]/[(2)^n*sqrt(5)]
*/


	return 0;
}