#include <bits/stdc++.h>
using namespace std;

// int subset(int input[], int n, int output[][20], int row = 0, int index = 0) {
//   	if(index >= n) {
//       	return row; 
//     }

//   	output[row][0] = 1;
//   	output[row][1] = input[index];
//   	//cout << input[index] << endl;
//   	int lastRow = row;
//   	for(int i = 0; i < lastRow; i++){
//       	int addLocation = output[i][0];
//       	for(int j = 0; j <= addLocation; j++){
//           	output[row+1][j] = output[i][j];
//           	if(j != 0) {
//             	//cout << output[i][j] << " ";
//             }
//         }
//       	output[row+1][addLocation+1] = input[index];
//       	//cout << input[index] << endl;
//       	output[row+1][0]++;
//       	row++;
//     }
//     row = subset(input, n, output, row+1, index+1);
//   	return row;
// }

void subset(int arr[],int n)
{
	int  count = pow(2,n);
	// The outer for loop will run 2^n times to print all subset .
	// Here variable i will act as a binary counter
	for (int i = 0; i < count; i++)
	{
		// The inner for loop will run n times , As the maximum number of elements a set can have is n
		// This loop will generate a subset
		for (int j = 0; j < n; j++)
		{
			// This if condition will check if jth bit in binary representation of  i  is set or not
			// if the value of (i & (1 << j)) is greater than 0 , include arr[j] in the current subset
			// otherwise exclude arr[j]
			if ((i & (1 << j)) > 0)
				cout << arr[j] << " ";
		}
		cout << "\n";
	}
}


int main()
{

  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  subset(input, length);
  
//   int size = subset(input, length);

//   for( int i = 0; i < size; i++) { 
// 	for( int j = 1; j <= output[i][0]; j++) { 
// 		cout << output[i][j] << " ";
//     }
//     cout << endl;
//   }    
    
    
    return 0;
}
