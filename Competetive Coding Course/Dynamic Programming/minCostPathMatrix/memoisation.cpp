#include <bits/stdc++.h>
using namespace std;
/*
3 4
3 4 1 2
2 1 8 9
4 7 8 1

*/


int minCostPathHelper(int** input, int m, int n, int i, int j, int** output){
    // i, j is our position in matrix
    if(i>=m || j>=n){
        return INT_MAX;
    }
    else if(i==m-1 && j==n-1){
        return input[i][j];
    }
    else{
        //Check if ans already exists
        if(output[i][j] != -1){
            return output[i][j];
        }

        int a= minCostPathHelper(input, m , n, i+1,j,output);
        int b= minCostPathHelper(input, m , n, i,j+1,output);
        int c= minCostPathHelper(input, m , n, i+1,j+1,output);
        
        int ans= input[i][j]+min(a,min(b,c));

        //Save ans for duture use
        output[i][j]=ans;
        return ans;
    }
}


int minCostPath(int** input, int m, int n){
    int**output=new int* [m];
    for(int i=0;i<m;i++){
        output[i]=new int[n];
        for(int j=0;j<n;j++){
            output[i][j]=-1;
        }
    }
    return minCostPathHelper(input, m , n , 0 , 0,output);
}
int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}
