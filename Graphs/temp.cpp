#include <bits/stdc++.h>
using namespace std;

void print(int** adj_mat, int n, int start, bool* visited){
    cout<<start<<" ";
    visited[start]= true;

    for(int i=0 ; i < n ; i++){
        if( i== start){
            continue;
        }
        if(adj_mat[start][i] == 1){
            if(visited[i]==true){
                continue;
            }
            print(adj_mat,n,i,visited);
        }
    }
}

int main()
{

    int n,e;
    cin>>n>>e;
    int** adj_mat = new int*[n];
    for(int i=0;i<n;i++){
        adj_mat[i] = new int[n];
        for(int j = 0; j<n; j++){
            adj_mat[i][j]= 0;
        }
    }    
    for(int i = 0; i<e ; i++){
        int first, second;
        cin>>first>>second;
        adj_mat[first][second]=1;
        adj_mat[second][first] = 1;
    }

    bool* visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }

    print(adj_mat, n, 0, visited);

    
    return 0;
}
