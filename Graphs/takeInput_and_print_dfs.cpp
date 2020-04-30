#include <bits/stdc++.h>
using namespace std;

void print( int** adjacancy_matrix, int num_nodes, int start, bool* visited){

    cout<< start<<endl;
    visited[start]= true;
    
    for(int i= 0; i<num_nodes;i++){
        if(i == start){
            continue;
        }
        if(adjacancy_matrix[start][i] == 1){
            if(visited[i]){
                continue;
            }
            print(adjacancy_matrix, num_nodes, i, visited);
        }
    }

}

int main()
{
    int num_nodes;
    int edges;
    cin>>num_nodes>>edges;

    int** adjacancy_matrix = new int*[num_nodes];

    for(int i=0; i<num_nodes ; i++){

        adjacancy_matrix[i] = new int[num_nodes];
        for(int j=0 ; j<num_nodes ; j++){
            adjacancy_matrix[i][j] = 0;
        }

    } // We have created our adjacancy matrix upto this point and initialised it to 0

    // Now we have to take input in the matrix

    for( int i = 0; i < edges ; i++) {
        int first,second;
        cin>>first>>second;
        adjacancy_matrix[first][second] = 1;
        adjacancy_matrix[second][first] = 1;
    }// Input done and adj_mat ready with true values

    // Created a visited array to keep track of already visited nodes
    bool* visited = new bool[num_nodes];

    for(int i = 0; i< num_nodes ; i++){
        visited[i] = false;
    }

    //Print
    print(adjacancy_matrix, num_nodes, 0, visited);

    return 0;
}
