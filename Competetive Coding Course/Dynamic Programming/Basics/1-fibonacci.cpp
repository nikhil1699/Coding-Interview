#include <bits/stdc++.h>
using namespace std;

int fibonacciDPHelper(int n, int* ans){
     //Memoisation: Wehere we start storing our recursve answers
     // Memoisation is a top down approach
     // Badi prblem se chooti problem ki taraf jaana
    // Generally Recursive
     if(n<=1){
        return n;
    }
    // Check if ans already exists
    // For this question we have to check if we have already calculated the nth fibonacci number
    // We know that nth fibonacci is present at ans[i]
    // There will already be garbage there if not initialised beforehand
    // Hence we initialised by -1
    // Now when we {see that at any location if -1 is kept, means we are coming on that position for first time
    if(ans[n] != -1)
        return ans[n]; // Anything except -1 will be ans due to recursion
    }
    int sma1=fibonacciDPHelper(n-1,ans);
    int sma2=fibonacciDPHelper(n-2, ans);
    
    ans[n]=sma1+sma2; // Saving for future use
    return ans[n]; //return

}
int fibonacciDP(int n){
    //O(n)
    //This approach is known as Memoisation
    int* ans=new int[n+1];//Dynaic allocation of Array
    for (int i = 0; i <=n; i++)
    {
        ans[i]=-1;
    }
    

    return fibonacciDPHelper(n,ans);
}


//Iterative solutiom
// First fill our smallest problem's solution which we already know and fill rest

int fibonacciIterative(int n){
    // Dynamic Programming is a bottom up approach
    // Choti problem se badi k taraf jaana
    //Generally iterative
    int* ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;

    for(int i=2;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}

int fibonacci(int n){
    // O(2^n)
    if(n<=1){
        return n;
    }
    int sa1=fibonacci(n-1);
    int sa2=fibonacci(n-2);   
    return sa1+sa2;
} 


int main()
{
    fibonacci(22);
    fibonacciDP(22);
    fibonacciIterative(22);
    
    
    return 0;
}
