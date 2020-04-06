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

BinaryTreeNode<int>* construct(int* postOrder, int postStart, int postEnd,int* inOrder,int inStart, int inEnd){
    if(postStart>postEnd || inStart>inEnd){
        return NULL;
    }
    int val=postOrder[postEnd];
    BinaryTreeNode<int>* temp=new BinaryTreeNode<int>(val);
    int k=0;
    for(int i=inStart;i<=inEnd;i++){
        if(val==inOrder[i]){
            k=i;
            break;
        }
    }
    temp->Left=construct(postOrder,postStart,postStart+k-inStart-1,inOrder,inStart,k-1);
    temp->Right=construct(postOrder, postOrder+k-inStart,postEnd-1,inOrder,k+1,inEnd);
    return temp;
}


BinaryTreeNode<int>* buildTree(int* postOrder, int postLength, int* inOrder, int inLength){
    int postStart=0;
    int postEnd=postLength-1;
    int inStart=0;
    int inEnd=inLength-1;
    return construct(postOrder,postStart,postEnd,inOrder,inStart,inEnd);
}

