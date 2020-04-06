# Python3 program to print the 
# smallest integer with n 
# factors or more 
MAX = 10000000001; 

# array to store 
# prime factors 
factor = [0] * MAX; 

# function to generate all 
# prime factors of numbers 
# from 1 to 10^6 
def generatePrimeFactors(): 
	
	factor[1] = 1; 

	# Initializes all the 
	# positions with their value. 
	for i in range(2, MAX): 
		factor[i] = i; 

	# Initializes all 
	# multiples of 2 with 2 
	i = 4
	while(i < MAX): 
		factor[i] = 2; 
		i += 2; 

	# A modified version of 
	# Sieve of Eratosthenes 
	# to store the smallest 
	# prime factor that 
	# divides every number. 
	i = 3; 
	while(i * i < MAX): 

		# check if it has 
		# no prime factor. 
		if (factor[i] == i): 

			# Initializes of j 
			# starting from i*i 
			j = i * i; 
			while(j < MAX): 

				# if it has no prime factor 
				# before, then stores the 
				# smallest prime divisor 
				if (factor[j] == j): 
					factor[j] = i; 
				j += i; 
		i += 1; 

# function to calculate 
# number of factors 
def calculateNoOFactors(n): 
	if (n == 1): 
		return 1; 

	ans = 1; 

	# stores the smallest prime 
	# number that divides n 
	dup = factor[n]; 

	# stores the count of 
	# number of times a 
	# prime number divides n. 
	c = 1; 

	# reduces to the next 
	# number after prime 
	# factorization of n 
	j = int(n / factor[n]); 

	# false when prime 
	# factorization is done 
	while (j != 1): 

		# if the same prime number 
		# is dividing n, then we 
		# increase the count 
		if (factor[j] == dup): 
			c += 1; 

		# if its a new prime factor 
		# that is factorizing n, then 
		# we again set c=1 and change 
		# dup to the new prime factor, 
		# and apply the formula 
		# explained above. 
		else: 
			dup = factor[j]; 
			ans = ans * (c + 1); 
			c = 1; 

		# prime factorizes a number 
		j = int(j / factor[j]); 

	# for the last prime factor 
	ans = ans * (c + 1); 

	return ans; 

# function to find the 
# smallest integer with 
# n factors or more. 
def smallest(n): 
	i = 1; 
	while(True): 
		
		# check if no of 
		# factors is more 
		# than n or not 
		if (calculateNoOFactors(i) >= n): 
			return i; 
		i += 1; 

# Driver Code 

# generate prime factors 
# of number upto 10^6 
generatePrimeFactors(); 

n = 4; 
print(smallest(n)); 

# This code is contributed by mits 
