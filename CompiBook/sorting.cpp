#include<bits/stdc++.h>
using namespace std;

//O(n^2)
void bubbleSort(int* A){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (array[j] > array[j+1]) {
				swap(array[j],array[j+1]);
			}
		}
	}
}
//O(nlog(n))
//Merge Sort Algo
vector<int> v = {4,2,5,3,5,8,3};
sort(v.begin(),v.end()); //Ascending Sort
sort(v.rbegin(),v.rend()); // Descending Sort

//Ordinary Array
int n = 7; // array size
int a[] = {4,2,5,3,5,8,3};
sort(a,a+n);

//Sorting a String s
string s = "monkey";
sort(s.begin(), s.end());

/*
Pairs ( pair ) are sorted primarily according to their first elements ( first ).
However, if the first elements of two pairs are equal, they are sorted according to
their second elements ( second ):

In a similar way, tuples ( tuple ) are sorted primarily by the first element,
secondarily by the second element, etc. 2
*/
vector<pair<int,int>> v;
v.push_back({1,5});
v.push_back({2,3});
v.push_back({1,2});
sort(v.begin(), v.end());

vector<tuple<int,int,int>> v;
v.push_back({2,1,4});
v.push_back({1,5,3});
v.push_back({2,1,3});
sort(v.begin(), v.end());


bool f(int x, int y){
	return x>y;// Or any other way you want to sort two elements
}
sort(v.begin(), v.end(),f);

//Binary Search is applied on sorted arrays.
bool isPresent=binary_search(v.begin(),v.end(),4/*This s the value to be found*/);
auto it1=lower_bound(v.begin(), v.end(),100);//Returns pointer to first occurance of an element less than or equal to 100
// For Array auto k = lower_bound(array,array+n,x)
//upper_bound returns a pointer to the first array element whose value is
//larger than x .
//upper_bound-lower_bound is the number of times that number is present in an  array or vector


**********************************
/*An important use for binary search is to find the position where the value of a
function changes.Suppose that we wish to find the smallest value k that is a
valid solution for a problem.We are given a function ok ( x ) that returns true if x
is a valid solution and false otherwise.
In addition, we know that ok ( x ) is false
when x < k and true when x ≥ k .

//ok is the function which returns true or false
x		:0 1 2......k-1 k k+1....	
ok(x)	:f f f...... f  t  t.....
*/
int x = -1;
for (int i = z; i >= 1; i = i/2) {
while (!ok(x+i))
{ 
	x += i;
}
// currently we have largest value of x for which ok is false
}
int k = x+1;//return k
//The initial
//jump length z has to be large enough, for example some value for which we know
//beforehand that ok ( z ) is true .



***************************
/*
Binary search can also be used to find the maximum value for a function that is
first increasing and then decreasing. Our task is to find a position k such that
• f ( x ) < f ( x + 1) when x < k , and
• f ( x ) > f ( x + 1) when x ≥ k .
The idea is to use binary search for finding the largest value of x for which
f ( x ) < f ( x + 1). This implies that k = x + 1 because f ( x + 1) > f ( x + 2). The following
code implements the search:
*/
int x = -1;
for (int b = z; b >= 1; b /= 2) {
while (f(x+b) < f(x+b+1)) x += b;
}
int k = x+1;









int main(){
	

	return 0;
}