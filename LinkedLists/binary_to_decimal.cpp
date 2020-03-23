/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int lengthofLL(ListNode*head){
        ListNode*t=head;
        int count=0;
        while(t!=NULL){
            count=count+1;
            t=t->next;
        }
        return count;
    }
    
    
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;int ans=0;
        int length=lengthofLL(head);
        while(temp != NULL){
            for(int n=length-1;n>=0;n--){
                ans=ans+ (temp->val)*pow(2,n);
                temp=temp->next;
            }
        }
        return ans;
    }
};


/*
Bit manipulation solution
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ret = 0;
        while(head)
        {
            ret <<= 1;
            ret |= head->val;
            head = head->next;
        }
        return ret;
    }
};




*/