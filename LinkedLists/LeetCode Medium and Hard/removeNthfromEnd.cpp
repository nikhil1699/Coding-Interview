#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int Data;
	Node* next;

	Node(int Data){
		this-> Data=Data;
		next=NULL;
	}
};
Node* removeNthfromEnd(Node* head, int n){
    Node*temp=head;
    int l=0;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    n=l-n;
    temp=head;
    int x=0;
    while(x<(n-1)){
        temp=temp->next;
        x++;
    }

    Node* del=temp->next;
    if(del==NULL){
        return NULL;
    }
    if((n-1)<0){
        return temp->next;
    }
    temp->next=temp->next->next;
    delete(del);
    return head;
    
}

int main(){

}