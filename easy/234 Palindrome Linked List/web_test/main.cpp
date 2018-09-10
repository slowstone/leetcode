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
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true; 
        ListNode* slow = head; 
        ListNode* fast = head;
        ListNode* prev = nullptr; 
        while(fast!=nullptr && fast->next!=nullptr)
        {
            prev = slow; 
            slow = slow->next; 
            fast = fast->next->next; 
        }
        // reverse the last half 
        if(prev)
        {
            prev->next = nullptr; 
        }
        ListNode* node = nullptr; 
        while(slow!=nullptr)
        {
            ListNode* next = slow->next; 
            slow->next = node; 
            node = slow; 
            slow = next; 
        }
        //上述过程是进行链表翻转
        while(node!=nullptr && head!=nullptr)
        {
            if(node->val != head->val) return false; 
            node = node->next; 
            head = head->next; 
        }
        return true; 
    }
};