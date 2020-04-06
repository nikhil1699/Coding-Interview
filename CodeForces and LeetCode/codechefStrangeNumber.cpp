
// #include <bits/stdc++.h> 
// using namespace std; 

// const long long MAX = 1000000001; 

// // array to store prime factors 
// long long factor[MAX] = { 0 }; 

// // function to generate all prime factors 
// // of numbers from 1 to 10^6 
// void generatePrimeFactors() 
// { 
// 	factor[1] = 1; 

// 	// Initializes all the positions 
// 	// with their value. 
// 	for (long long i = 2; i < MAX; i++) 
// 		factor[i] = i; 

// 	// Initializes all multiples of 2 with 2 
// 	for (long long i = 4; i < MAX; i += 2) 
// 		factor[i] = 2; 

// 	// A modified version of Sieve of 
// 	// Eratosthenes to store the smallest 
// 	// prime factor that divides every number. 
// 	for (long long i = 3; i * i < MAX; i++) { 

// 		// check if it has no prime factor. 
// 		if (factor[i] == i) { 

// 			// Initializes of j starting from i*i 
// 			for (long long j = i * i; j < MAX; j += i) { 

// 				// if it has no prime factor 
// 				// before, then stores the 
// 				// smallest prime divisor 
// 				if (factor[j] == j) 
// 					factor[j] = i; 
// 			} 
// 		} 
// 	} 
// } 

// // function to calculate number of factors 
// int calculateNoOFactors(long long n) 
// { 
// 	if (n == 1) 
// 		return 1; 

// 	long long ans = 1; 

// 	// stores the smallest prime number 
// 	// that divides n 
// 	long long dup = factor[n]; 

// 	// stores the count of number of times 
// 	// a prime number divides n. 
// 	long long c = 1; 

// 	// reduces to the next number after prime 
// 	// factorization of n 
// 	long long j = n / factor[n]; 

// 	// false when prime factorization is done 
// 	while (j != 1) { 

// 		// if the same prime number is dividing n, 
// 		// then we increase the count 
// 		if (factor[j] == dup) 
// 			c += 1; 

// 		/* if its a new prime factor that is 
// 		factorizing n, then we again set c=1 
// 		and change dup to the new prime factor, 
// 		and apply the formula explained above. */
// 		else { 
// 			dup = factor[j]; 
// 			ans = ans * (c + 1); 
// 			c = 1; 
// 		} 

// 		// prime factorizes a number 
// 		j = j / factor[j]; 
// 	} 

// 	// for the last prime factor 
// 	ans = ans * (c + 1); 

// 	return ans; 
// } 

// // function to find the smallest integer 
// // with n factors or more. 
// int smallest(long long n) 
// { 
// 	for (long long i = 1;; i++) 

// 		// check if no of factors is more 
// 		// than n or not 
// 		if (calculateNoOFactors(i) == n) 
// 			return i; 
//         else{
//             return 0;
//         }
// } 

// // Driver program to test above function 
// int main() 
// { 
// 	// generate prime factors of number 
// 	// upto 10^6 
// 	generatePrimeFactors(); 

// 	long long n = 4; 
// 	cout << smallest(n); 
// 	return 0; 
// } 




// c++ program to print the smallest 
// integer with n factors or more 
#include <bits/stdc++.h> 
using namespace std; 

const int MAX = 1000001; 

// array to store prime factors 
int factor[MAX] = { 0 }; 

// function to generate all prime factors 
// of numbers from 1 to 10^6 
void generatePrimeFactors() 
{ 
	factor[1] = 1; 

	// Initializes all the positions 
	// with their value. 
	for (int i = 2; i < MAX; i++) 
		factor[i] = i; 

	// Initializes all multiples of 2 with 2 
	for (int i = 4; i < MAX; i += 2) 
		factor[i] = 2; 

	// A modified version of Sieve of 
	// Eratosthenes to store the smallest 
	// prime factor that divides every number. 
	for (int i = 3; i * i < MAX; i++) { 

		// check if it has no prime factor. 
		if (factor[i] == i) { 

			// Initializes of j starting from i*i 
			for (int j = i * i; j < MAX; j += i) { 

				// if it has no prime factor 
				// before, then stores the 
				// smallest prime divisor 
				if (factor[j] == j) 
					factor[j] = i; 
			} 
		} 
	} 
} 

// function to calculate number of factors 
int calculateNoOFactors(int n) 
{ 
	if (n == 1) 
		return 1; 

	int ans = 1; 

	// stores the smallest prime number 
	// that divides n 
	int dup = factor[n]; 

	// stores the count of number of times 
	// a prime number divides n. 
	int c = 1; 

	// reduces to the next number after prime 
	// factorization of n 
	int j = n / factor[n]; 

	// false when prime factorization is done 
	while (j != 1) { 

		// if the same prime number is dividing n, 
		// then we increase the count 
		if (factor[j] == dup) 
			c += 1; 

		/* if its a new prime factor that is 
		factorizing n, then we again set c=1 
		and change dup to the new prime factor, 
		and apply the formula explained above. */
		else { 
			dup = factor[j]; 
			ans = ans * (c + 1); 
			c = 1; 
		} 

		// prime factorizes a number 
		j = j / factor[j]; 
	} 

	// for the last prime factor 
	ans = ans * (c + 1); 

	return ans; 
} 

// function to find the smallest integer 
// with n factors or more. 
int smallest(int n) 
{ 
	for (int i = 1;; i++) 

		// check if no of factors is more 
		// than n or not 
		if (calculateNoOFactors(i) >= n) 
			return i; 
} 

// Driver program to test above function 
int main() 
{ 
	// generate prime factors of number 
	// upto 10^6 
	generatePrimeFactors(); 

	int n = 4; 
	cout << smallest(n); 
	return 0; 
} 
