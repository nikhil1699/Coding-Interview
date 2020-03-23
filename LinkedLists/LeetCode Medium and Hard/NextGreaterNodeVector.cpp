/*
Test Cases
Example 1:

Input: [2,1,5]
Output: [5,5,0]

Example 2:

Input: [2,7,4,3,5]
Output: [7,0,5,5,0]

Example 3:

Input: [1,7,5,1,9,2,5,1]
Output: [7,9,9,9,0,5,0,0]


*/



class Solution {
public:
	vector<int> nextLargerNodes(ListNode* head) {
		ListNode *curr = head, *prev = nullptr, *nxt;
 
 //Revese List
 while(curr)
 {
     nxt = curr->next;
     curr->next = prev;
     prev = curr;
     curr = nxt;
 }
 
 curr = prev;
 stack<int> st;
 vector<int>ret;

 while(curr)
 {
     while(!st.empty() && st.top() <= curr->val)
         st.pop();
     
     
     if(st.empty())
     ret.push_back(0);
     else
     ret.push_back(st.top());
     
     st.push(curr->val);
     
     curr = curr->next;
 }
 
 reverse(ret.begin(), ret.end());
 return ret;
	}
};

