
#include <bits/stdc++.h> 
using namespace std; 
/*
Efficient Approach” If all the elements of the array are positive.
 If a subarray has sum greater than the given sum then there is no possibility,
 that adding elements to the current subarray the sum will be x (given sum).

 Idea is to use a similar approach to a sliding window.
 Start with an empty subarray, add elements to the subarray until the sum is less than x.
 If the sum is greater than x, remove elements from the start of the current subarray.

    Algorithm:
        Create three variables, l=0, sum = 0
        Traverse the array from start to end.
        Update the variable sum by adding current element, sum = sum + array[i]
        If the sum is greater than the given sum,
         update the variable sum as sum = sum – array[l], and update l as , l++.
        If the sum is equal to given sum, print the subarray and break the loop.



The complete solution is

    Maintain start and last index to store and print these values 
    Iterate the complete array.
    Add array elements to cuursum
    If currsum becomes greater than S, then remove elements starting from start index, till it become less than or equal to S, and increement start.
    if currsum becomes equals to S, then print the starting and last index
    if the currsum never maches to S, then print -1




*/

int subArraySum(vector<int> v, int n, int sum){
    int currSum=0;
    int start=0; int i;
    for( i=1;i<n;i++){
        while(currSum > sum && start <i-1){
            currSum-=v[start];
            start++;
        }

        if(currSum==sum){
            cout<< start << " " << i-1;
            return 1;
        }

        if(i<n){
            currSum+=v[i];
        }
    }
    cout<<" Not Found "<<endl;
    return 0;
}











/* Returns true if the there is a subarray of 
arr[] with a sum equal to 'sum' otherwise 
returns false. Also, prints the result */

int subArraySum(int arr[], int n, int sum) 
{ 
	/* Initialize curr_sum as value of 
	first element and starting point as 0 */

	int curr_sum = arr[0], start = 0, i; 

	/* Add elements one by one to curr_sum and 
	if the curr_sum exceeds the sum, 
	then remove starting element */
    
	for (i = 1; i <= n; i++) 
	{ 
		// If curr_sum exceeds the sum, 
		// then remove the starting elements 
		while (curr_sum > sum && start < i - 1) 
		{ 
			curr_sum = curr_sum - arr[start]; 
			start++; 
		} 

		// If curr_sum becomes equal to sum, 
		// then return true 
		if (curr_sum == sum) 
		{ 
			cout << "Sum found between indexes "
				<< start << " and " << i - 1; 
			return 1; 
		} 

		// Add this element to curr_sum 
		if (i < n) 
		curr_sum = curr_sum + arr[i]; 
	} 

	// If we reach here, then no subarray 
	cout << "No subarray found"; 
	return 0; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {15, 2, 4, 8, 9, 5, 10, 23}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int sum = 23; 
	subArraySum(arr, n, sum); 
	return 0; 
} 
