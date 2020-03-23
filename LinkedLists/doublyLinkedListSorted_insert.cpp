class Node{
      int data;
      Node* next;
      Node* prev;
};




Node* SortedInsert(Node *head,int data)
{ 
   Node* temp = head;
    
   //Initializing the new Node 
   Node* newNode = new Node(); 
   newNode->data = data;
   newNode->next = NULL;
   newNode->prev = NULL;
    
   // If the List is empty point the head to the new node 
   if(temp == NULL)
   {
       temp = newNode;
       head = temp;
       return head;
   }
    
   //Check if the data in the new node is bigger
   // or smaller than each node in the list. if it's
   // bigger, move to the next node in the list. 
   // If it's the last node stop.
   while((newNode->data > temp->data) && temp->next != NULL) 
   {
       temp = temp->next;       
   }     
    
   //If it was the last node and the data is still
   //bigger this new node will be added to the tail
   if(temp->next == NULL && newNode->data > temp->data )
   {
       newNode->prev = temp;
       temp->next = newNode;
       return head;         
   }
    
   //If this was smaller than the node pointed by temp
   //we add new node before it 
   newNode->prev = temp->prev;
   temp->prev = newNode;
   newNode->next = temp;
    
   //If there are elements before we need to link its
   //next to our new node
   if(newNode->prev != NULL)
   { 
       newNode->prev->next = newNode;
   }
    
   //If there are no elements before it, our node
   //is the first one so we point the head/temp to it
   if(newNode->prev == NULL)
   {
       temp = newNode;
       return temp;
   }
       
   return head;   
}
