#include <bits/stdc++.h>
using namespace std;

void printBFS(int** adjacancy_matrix, int num_nodes, int start, bool* visited){

    queue<int> pv;
    pv.push(start);
    visited[start] = true;

    while(! pv.empty()){
        int currV = pv.front();
        pv.pop();
        cout<<currV<<endl;

        for(int i=0;i<num_nodes;i++){
            if(adjacancy_matrix[currV][i]==1 && !visited[i]){
                pv.push(i);
                visited[i]=true;
            }
        }
    }
}

void printDFS( int** adjacancy_matrix, int num_nodes, int start, bool* visited){

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
            printDFS(adjacancy_matrix, num_nodes, i, visited);
        }
    }

}

void DFS(int** adjacancy_matrix, int num_nodes){
    bool* visited = new bool[num_nodes];
    
    for(int i = 0; i< num_nodes ; i++){
        visited[i] = false;
    }

    // Use a for loop on visited array and jaise hi non visited mila, to make that as starting vertex

    for(int i=0;i<num_nodes;i++){
        if(!visited[i]){
            printDFS(adjacancy_matrix, num_nodes,i,visited);
        }
    }
    delete[] visited;

}

void BFS(int** adjacancy_matrix, int num_nodes){
    bool* visited = new bool[num_nodes];
    
    for(int i = 0; i< num_nodes ; i++){
        visited[i] = false;
    }

    // Use a for loop on visited array and jaise hi non visited mila, to make that as starting vertex

    for(int i=0;i<num_nodes;i++){
        if(!visited[i]){
            printBFS(adjacancy_matrix, num_nodes,i,visited);
        }
    }
    delete[] visited;
}


int main(){
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

 
    //Print
    cout<<"BFS :"<<endl;
    BFS(adjacancy_matrix, num_nodes);
    cout<<"DFS :"<<endl;
    DFS(adjacancy_matrix, num_nodes);

    return 0;
}

