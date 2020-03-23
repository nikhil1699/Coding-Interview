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
void printStatic(Node* head){
	Node*temp=head;
	cout<<"Printing from Static function "<<endl;
	while(temp != NULL){
		
		cout<<temp->Data<<" "<<endl;
		temp=temp->next;
	}
}

void printDynamic(Node* dynamic_head){
	Node* temp=dynamic_head;
	cout<<"Printing from dynamic function "<<endl;
	while(temp != NULL){
		
		cout<<temp->Data<<" "<<endl;
		temp=temp->next;
	}
}
int main(){
	//Statically
	Node n1(1);
	Node* head=&n1;
	Node n2(2);
	n1.next = &n2;
	cout<<"Printing Statically Normally "<<n1.Data<<" "<<n2.Data<<endl;
	cout<<"Printing first element Statically using Head "<<head->Data<<" "<<endl;
	//Dynamically

	Node* n3= new Node(30);
	Node* dynamic_head=n3;
	Node* n4=new Node(40);
	n3->next=n4;
	cout<<"Printing Dynamically Normally "<<n3->Data<<" "<<n4->Data<<endl;
	cout<<"Printing first element Dynamically using head "<<dynamic_head->Data<<endl;
	printStatic(head);
	printDynamic(dynamic_head);


	return 0;
}