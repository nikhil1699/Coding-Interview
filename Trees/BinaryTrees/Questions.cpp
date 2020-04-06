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

int sum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    else{
        int leftAns=sum(root->Left);
        int rightAns=sum(root->Right);
        return root->data+leftAns+rightAns;  
        }

}

int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int ans=0;
    int lh=height(root->Left);
    int rh=height(root->Right);
    return 1+max(lh,rh);
}

bool isBalanced(BinaryTreeNode<int>* root){
    if(root==NULL){
        return true;
    }
    bool ans=true;
    int lh=height(root->Left);
    int rh=height(root->Right);
    if(lh-rh<=1 && lh-rh>=-1){
        ans=isBalanced(root->Left)&&isBalanced(root->Right);
    }
    else{
        bool temp=false;
        if(temp==false){
            ans=false;
        }
    }
    return ans;
}

BinaryTreeNode<int>* removeLeaf(BinaryTreeNode<int>* root){
    if(root==NULL){
        return NULL;
    }
    if(root->Left==NULL && root->Right==NULL){
        return NULL;
    }
    else{
        root->Left=removeLeaf(root->Left);
        root->Right-removeLeaf(root->Right);
        return root;
    }
}

