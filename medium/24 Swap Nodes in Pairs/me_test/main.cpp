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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* next = head->next;
        ListNode* pre = head;
        ListNode* ppre = nullptr;
        while(next != nullptr){
            pre->next = next->next;
            next->next = pre;
            if(pre == head)
                head = next;
            if(ppre != nullptr)
                ppre->next = next;
            ppre = pre;
            pre = pre->next;
            if(pre == nullptr)
                break;
            next = pre->next;
        }
        return head;
    }
};