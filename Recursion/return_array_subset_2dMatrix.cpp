#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

int subsetHelper(int input[], int n, int start, int output[][20])
{
	if (start == n)
	{
		output[0][0] = 0;
		return 1;
	}
	int smallSize = subsetHelper(input, n, start + 1, output);
	for (int i = 0; i < smallSize; i++)
	{

		output[i + smallSize][0] = output[i][0] + 1;
		output[i + smallSize][1] = input[start];
		for (int j = 1; j <= output[i][0]; j++)
		{

			output[i + smallSize][j + 1] = output[i][i];
		}
	}
	return 2 * smallSize;
}

int subset(int input[], int n, int output[][20])
{
	return subsetHelper(input, n, 0, output);
}

int main()
{
	int a[6] = {1, 2, 2, 3, 4, 2};
	int output[100][20];
	subset(a, 6, output);
	for (int i = 0; i <= 5; i++)
	{

		cout << a[i] << endl;
	}
	return 0;
}
