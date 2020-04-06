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
***********************************************************************************************************************


BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE) {
		return NULL;
	}

	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	int rInS = rootIndex + 1;
	int rInE = inE;
	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}

BinaryTreeNode<int>* buildTree(int* in, int* pre, int size) {
	return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

int main(){


}