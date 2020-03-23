#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
	public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode(T data) {
		this->data = data;
	}

};

bool containsX(TreeNode<int>* root, int x){
    if(root==NULL){
        return 0;
    }
    if(root->data == x){
        return true;
    }
    bool ans=false;
    for(int i=0;i<root->children.size();i++){
        bool temp=containsX(root->children[i],x);
        if(temp==1 && ans==0){
            ans=temp;
        }
    }
    return ans;

}



int main(){

    return 0;
}