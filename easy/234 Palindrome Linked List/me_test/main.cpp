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
    bool isPalindrome(ListNode* head) {
        stack<ListNode *> Lstack;
        for(ListNode* tmp = head;tmp != NULL;tmp = tmp->next){
        	Lstack.push(tmp);
        }
        for(ListNode* tmp = head;tmp != NULL;tmp = tmp->next){
        	ListNode* stacktmp = Lstack.top();
        	Lstack.pop();
        	if(stacktmp->val != tmp->val){
        		return false;
        	}
        }
        return true;
    }
};