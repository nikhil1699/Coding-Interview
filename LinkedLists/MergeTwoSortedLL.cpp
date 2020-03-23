Node* MergeTwo(Node* head1, Node* head2){
	Node* fHead=NULL;
	Node* fTail=NULL;

	while(head1 != NULL || head2 !=NULL){
		if(head1->data < head2->data){
			if(fHead==NULL){
				fHead=head1;
				fTail=head1;
			}
			else{
				//Next of tail always points to smaller element
				fTail->next=head1;
				fTail=head1;
			}
			head1=head1->next;
		}
		else{
			if(fHead==NULL){
				fHead=head2;
				fTail=head2;
			}
			else{
				fTail->next=head2;
				fTail=head2;
			}
			head2=head2->next;
		}
	}

	if(head1 !=NULL){
		fTail->next=head1;
	}
	if(head2 !=NULL){
		fTail->next=head2;

		return fHead;
	}



	
}