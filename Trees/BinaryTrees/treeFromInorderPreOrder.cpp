#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* Left;
    BinaryTreeNode* Right;
    BinaryTreeNode(T data){
        this->data=data;
        Left=NULL;
        Right=NULL;
    }
    ~BinaryTreeNode(){
        delete Left;delete Right;
    }

};

BinaryTreeNode<int>* construct(int* preOrder,int preStart,int preEnd,int*inOrder,int inStart, int inEnd){
    if(preStart>preEnd || inStart>inEnd){
        return NULL;
    }
    int val=preOrder[preStart];
    BinaryTreeNode<int>* temp=new BinaryTreeNode<int>(val);
    int k=0;
    for(int i=0;i<inEnd;i++){
        if(val==inOrder[i]){
            k=i;
            break;
        }
    }
    temp->Left=construct(preOrder,preStart+1,preStart+(k-inStart),inOrder,inStart,k-1);
    temp->Right=construct(preOrder,preStart+(k-inStart)+1,preEnd,inOrder,k+1,inEnd);

    return temp;
}


BinaryTreeNode<int>* buildTree(int* preOrder, int preLength, int* inOrder, int inLength){
    int preStart=0;
    int preEnd=preLength-1;
    int inStart=0;
    int inEnd=inLength-1;
    return construct(preOrder,preStart,preEnd,inOrder,inStart,inEnd);
}
int main(){


}