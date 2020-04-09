#include <bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible( int n, int row, int column){
    for(int i=row-1;i>=0;i--){
        //Checking in same column
        if(board[i][column]==1){
            return false;
        }
    }
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        //Upper left diagonal
        if(board[i][j]==1){
        return false;
        }
    }
    for(int i=row-1,j=column+1; i>=0 && j<n;i--,j++){
        //Upper right diagonal
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}

void nQueenHelper(int n, int row){
    if(row==n){
        // Base case
        // We have reached some solution
        // Print the board matrix
        //return
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    //Place at all possible positions and move to smaller problem
    for(int j=0;j<n;j++){
        if(isPossible(n,row,j)){
            board[row][j]=1;
            nQueenHelper(n,row+1);
            board[row][j]=0;
        }
    }
    return;
}
void placeNQueens(int n){
    memset(board,0,11*11*sizeof(int));//memset fills the particupal given block of memory with the given values
    nQueenHelper(n,0);//Starting with row 0

}

int main()
{
    /*
    Exploring all possible outcomes
    Implemented using recursive algorithm

    NQueen problem
    n*n matrix place n queens in this on the conditions that paths of none of the queen crosses each other
    queen can move in all 8 directions 
    
    */
    placeNQueens(4);
    
    
    return 0;
}
