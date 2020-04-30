
#include <bits/stdc++.h> 
using namespace std; 

int subArraySum(vector<int> v, int n, int sum) 
{ 
	int curr_sum; 

	// Pick a starting point 
	for (int i = 0; i < n; i++) 
	{ 
		curr_sum = v[i]; 

		// try all subarrays starting with 'i' 
		for (int j = i + 1; j <= n; j++) 
		{ 
			if (curr_sum == sum) 
			{ 
				cout << "Sum found between indexes "<< i << " and " << j - 1; 
				return 1; 
			} 
			if (curr_sum > sum || j == n) 
				break; 
		curr_sum = curr_sum + v[j]; 
		} 
	} 

	cout << "No subarray found"; 
	return 0; 
} 

// Driver Code 
int main() 
{ 
	vector<int> v = {15, 2, 4, 8, 9, 5, 10, 23}; 
	int n=v.size(); 
	int sum = 23; 
	subArraySum(v, n, sum); 
	return 0; 
} 

// This code is contributed 
// by rathbhupendra 
