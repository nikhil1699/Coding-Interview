#include <bits/stdc++.h>
using namespace std;


int minAbsDiff(int input[], int size){
    sort(input, input+size);
    int ans=input[1]-input[0];
    for(int i=0;i<size-1;i++){
        ans=min(ans,input[i+1]-input[i]);
    }
    return ans;
}

int main()
{
    /*
    When to use Greedy
    When we have a choice of having a optimal sub structure ie, just keep picking optimal
    Greedy Workout
    Minimun Absolute Difference in the Array
    1,3,2,5,4,11,7
    Minimum difference between any two elements
    */
   int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout<< minAbsDiff(input,size) << endl;
	
	return 0;


    
    
    return 0;
}
