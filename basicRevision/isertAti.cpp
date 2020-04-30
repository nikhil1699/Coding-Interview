#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};




Node*insertAti(Node*head, int i, int data){
    int count=0;
    Node* newNode = new Node(data);
    Node* temp = head;\

    if(head == NULL){
        return head;
    }
    if(i == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }

    while (count < i-1)
    {
        temp=temp->next;
        count++;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode; 

}



int main()
{
    
    
    
    return 0;
}
