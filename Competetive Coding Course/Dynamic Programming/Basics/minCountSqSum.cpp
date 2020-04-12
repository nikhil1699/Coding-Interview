#include<climits>
#include<algorithm>
int minCount(int n){
    
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    
    for (int i=4; i <= n; i++)
    {
        ans[i] = i;
        
        for (int j=1; j*j <= i; j++)
        {
            ans[i] = min(ans[i], 1+ans[i- j*j]);
        }
    }
    int result = ans[n];
    delete []ans;
    
    return result;
    
}