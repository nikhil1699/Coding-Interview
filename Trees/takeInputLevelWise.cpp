#include<bits/stdc++.h>

using namespace std;



template <typename T>
class TreeNode{
public:
	T data;
	vector<TreeNode*> children;
	TreeNode(T data){
		this->data=data;
	}
};

void printTree(TreeNode<int>* root){ 
	
	// 1:2,3,
	// 2:
	// 3:
	if(root==NULL){
		return; //Edge case, Not base case
	}
	//No need of writing base case as .size handles it
	cout<<root->data<<" : ";
	for(int i=0; i<root->children.size();i++){
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	// Now Recursion 
	for(int i=0;i< root->children.size();i++){
		printTree(root->children[i]);
	}

}


void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0){
        cout<<pending.front()->data<<":";
        for(int i=0;i<pending.front()->children.size();i++){
            cout<<pending.front()->children[i]->data;
            pending.push(pending.front()->children[i]);
            if(i<pending.front()->children.size()-1){
                cout<<",";
            }
        }
        cout<<endl;
        pending.pop();
    }
}

TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}


int countNodes(TreeNode<int>* root){
	int ans=1;
	for (int i = 0; i < root->children.size(); i++)
	{
		ans+= countNodes(root->children[i]);
	}
	return ans;
	
}

int sumOfNodes(TreeNode<int>* root) {
    int rootData = root->data;
    int smallSum=0;
    for(int i=0;i<root->children.size();i++){
       smallSum += sumOfNodes(root->children[i]); 
    }
    return smallSum+rootData;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int>* max = root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp = maxDataNode(root->children[i]);
        if(temp->data>max->data)
            max=temp;
    }
    return max;
}

void printAtLevelK(TreeNode<int>* root, int k){
    
    if(root==NULL){
        return;
    }

    if(k==0){
        cout<<root->data<<" "<<endl;
        return;
    }
    for(int i=0;i < root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}

int numLeafNodes(TreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	if(root->children.size()==0){
		return 1;
	}
	int smallAns=0;
	for (int i = 0; i < root->children.size(); i++)
	{
		smallAns=numLeafNodes(root->children[i]);
	}
	return smallAns;
	
}

void preOrder(TreeNode<int>*root){
	if(root==NULL){
		return ;
	}
	cout << root->data <<" ";
	for(int i=0;i< root->children.size();i++){
		preOrder(root->children[i]);
	} 
}

void postOrder(TreeNode<int>* root){
	if(root==NULL){
		return;
	}
	for(int i=0;i<root->children.size();i++){
		postOrder(root->children[i]);
	}
	cout<<root->data<<" ";
}

int main(){
	
	TreeNode<int>* root=takeInputLevelWise();
	// Print a tree
	printTree(root);



	return 0;
}