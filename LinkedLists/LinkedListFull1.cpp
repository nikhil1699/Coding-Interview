#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int data){
		this->data=data;
		next=NULL;
	}
};

Node* takeInput(){
	int data;
	cin>>data;
	Node*head=NULL;
	Node*tail=NULL;
	while(data !=-1){
		Node*newNode=new Node(data);
		if(head==NULL){
			head=newNode;
			tail=newNode;
		}
		else{
			tail->next=newNode;
			tail=tail->next;
		}
		cin>>data;
	}
	return head;
}

Node* deleteNode(Node* head, int i){
	Node* temp=head;
	if(i==0){
		head=temp->next;
		temp->next=NULL;
		delete(temp);
		return head;
	}
	else{
		for(int j=0;j<i-1;j++){
			temp=temp->next;
		}
		Node* a=temp->next;
		if(a==NULL){
			return head;
		}
		temp->next=a->next;
		delete(a);
		return head;
	}
}

Node* insertNode(Node *head, int i, int data) {
	Node *newNode = new Node(data);
	int count = 0;
	Node *temp = head;

	if(i == 0) {
		newNode -> next = head;
		head = newNode;
		return head;
	}

	while(temp != NULL && count < i - 1) {
		temp = temp -> next;
		count++;
	}
	if(temp != NULL) {
		Node *a = temp -> next;
		temp -> next = newNode;
		newNode -> next = a;
	}
	return head;
}




void Print(Node*head){
	Node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" "<<endl;
		temp=temp->next;
	}
}

int lengthOfLL(Node* head){
	Node* temp=head;
	int c=0;
	while(temp !=NULL){
		c++;
		temp=temp->next;
	}
	return c;
}

void printIthNode(Node* head, int i){
	Node* temp=head;
	int c=0;
	while(temp!=NULL){
		if(c==i){
			cout<<temp->data<<endl;
			return;
		}
		else{
			c++;
			temp=temp->next;
		}
	}
}

int main(){
	Node *head = takeInput();
	Print(head);
	cout<<lengthOfLL(head)<<endl;
	printIthNode(head,3);
	int i, data;
	cin >> i >> data;
	head = insertNode(head, i, data);
	Print(head);
	deleteNode(head,4);
	Print(head);

	return 0;
}