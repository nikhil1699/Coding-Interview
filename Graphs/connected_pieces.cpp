#include <bits/stdc++.h>
using namespace std;

void print(int** adj_mat, int n, int start, bool* visited){
    int init = start;
    while(init<n){
        if(visited[init] != false){
            init++;
            continue;
        }
        visited[init]= true;

    queue<int> q ;
    q.push(init);
    init++;
    vector<int> v1;

    while(!q.empty()){
        int x = q.front();
        v1.push_back(x);

        q.pop();

        for(int i = 0 ; i<n;i++){
            if(adj_mat[x][i] && !visited[i]){
                q.push(i);
                visited[i]= 1;
            }
        }
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;


    }
    return;


}



int main()
{
    int n,e;
    cin>>n>>e;
    
    int** adj_mat = new int*[n];
    for(int i=0;i<n;i++){
        adj_mat[i] = new int[n];
        for(int j=0;j<n;j++){
            adj_mat[i][j] = 0;
        }
    }
    for(int i = 0; i<e ; i++){
        int f, s;
        cin>>f>>s;
        adj_mat[f][s]= 1;
        adj_mat[s][f]= 1;
    }

    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]= false;
    }

    print(adj_mat, n, 0, visited);

    
    
    return 0;
}
