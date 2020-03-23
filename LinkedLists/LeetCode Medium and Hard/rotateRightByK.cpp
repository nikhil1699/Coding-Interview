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
Node* rotateRightByK(Node* head, int k){
    if(head==nullptr){
        return head;
    }
    int len=1;
    Node*tail=head;
    Node*newH=head;
    while(tail->next){
        tail=tail->next;
        len++;
    }
    tail->next=head;//circular
    if(k=k%len){
        for(int i=0;i<len-k;i++){
            tail=tail->next;
        }
    }
    newH=tail->next;
    tail->next=NULL;
    return newH;
}
