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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur != nullptr){
            if(n == 0)
                pre = head;
            else if(n < 0)
                pre = pre->next;
            n--;
            cur = cur->next;
        }
        if(pre != NULL){
            cur = pre->next;
            if(cur != NULL){
                pre->next = cur->next;
            }
        }
        else{
            cur = head;
            head = head->next;
        }
        delete(cur);
        return head;
    }
};