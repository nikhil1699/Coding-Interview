#include <bits/stdc++.h>
using namespace std;

int minCostPathHelper(int** input, int m, int n, int i, int j){
    // i, j is our position in matrix
    if(i>=m || j>=n){
        return INT_MAX;
    }
    else if(i==m-1 && j==n-1){
        return input[i][j];
    }
    else{
        int a= minCostPathHelper(input, m , n, i+1,j);
        int b= minCostPathHelper(input, m , n, i,j+1);
        int c= minCostPathHelper(input, m , n, i+1,j+1);
        return input[i][j]+min(a,min(b,c));
    }
}


int minCostPath(int** input, int m, int n){
    return minCostPathHelper(input, m , n , 0 , 0);
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
