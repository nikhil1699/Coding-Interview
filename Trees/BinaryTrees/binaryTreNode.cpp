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

void printTree(BinaryTreeNode<int>*root){
    
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<":";
    if(root->Left != NULL){
        cout<<"L "<<root->Left->data;
    }
    if(root->Right != NULL){
        cout<<" R "<<root->Right->data;
    }
    cout<< endl;


    printTree(root->Left);
    printTree(root->Right);

}

BinaryTreeNode<int>* takeInputLevelwise(){
    int rootData;
    cout<< "Enter root Data: " << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(leftChildData);
            front->Left=child;
            pendingNodes.push(child);
        }
        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(rightChildData);
            front->Right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}

BinaryTreeNode<int>* takeInputNormally(){
    //If user enters root -1 the no data means return  null
    int rootData;
    cout<< "Enter Data: " << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild=takeInputNormally();
    BinaryTreeNode<int>* rightChild=takeInputNormally();
    root->Left= leftChild;
    root->Right=rightChild;
    return root;
    
}

int countNode(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+countNode(root->Left)+countNode(root->Right);
}
bool isPresent(BinaryTreeNode<int>*root, int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    bool leftSearch=isPresent(root->Left,x);
    bool rightSearch=isPresent(root->Right,x);
    return leftSearch || rightSearch;
}
int heightOfTree(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    int temp1= heightOfTree(root->Left);
    int temp2= heightOfTree(root->Right);
    int ans=0;
    if(temp1>temp2){
        ans=temp1;
    }
    else{ans=temp2;}
    return ans+1;

}

void mirror_a_BinaryTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    mirror_a_BinaryTree(root->Left);
    mirror_a_BinaryTree(root->Right);
    BinaryTreeNode<int>* temp=NULL;
    temp=root->Left;
    root->Left=root->Right;
    root->Right=temp;
}

void inorder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }coding ninjas
    inorder(root->Left);
    cout<<root->data<<" ";
    inorder(root->Right);
    
}
int main(){
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    // BinaryTreeNode<int>* node3 = new BinaryTreeNode<int>(4);
    // BinaryTreeNode<int>* node4 = new BinaryTreeNode<int>(5);

    // root->Left=node1;
    // root->Right=node2;
    // node1->Left=node3;
    // node2->Right=node4;

    BinaryTreeNode<int>* root=takeInputLevelwise();
    printTree(root);
    cout<<endl;
    cout<<countNode(root);
    delete root;
    
}