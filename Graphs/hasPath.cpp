#include <bits/stdc++.h>
using namespace std;

bool hasPath(int** adj_mat, int n, int c, int d, int* visited){

    if(c==d){
        return 1;
    }
    int result = 0;
    for(int i=0; i<n; i++){
        if(adj_mat[c][i]==1 && visited[i]==0){
            visited[i] = 1;
            result = hasPath(adj_mat, n, i, d, visited);
            if(result == 1){
                return 1;
            }
        }
    }
    return result;

}

int main()
{
    int n,e;
    cin >> n >> e;
    
    int** adj_mat = new int*[n];
    for (int i = 0; i < n; i++)
    {
        adj_mat[i] = new int[n];

        for(int j = 0 ; j<n; j++){
            adj_mat[i][j] = 0;
        }
    }

    int* visited = new int[n];

    for(int i = 0; i<n; i++){
        visited[i] = 0;
    }

    for(int i = 0; i<e ; i++){
        int a,b;
        cin>>a>>b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
    }

    int c,d;
    cin>>c>>d;

    if(hasPath(adj_mat, n, c, d, visited)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    return 0;


    return 0;
}
