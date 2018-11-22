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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *res = new ListNode(0);
        ListNode *insertcur = res;
        while(head != NULL){
            ListNode *cur = head;
            ListNode *pre = NULL;
            ListNode *insertp = cur;
            while(cur->next != NULL){
                if(insertp->val > cur->next->val){
                    pre = cur;
                    insertp = cur->next;
                }
                cur = cur->next;
            }
            if(insertp == head)
                head = head->next;
            else
                pre->next = insertp->next;
            insertcur->next = insertp;
            insertp->next = NULL;
            insertcur = insertp;
        }
        return res->next;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *pre = res;
        ListNode *cur = head;
        while(cur && cur->next){
            if(cur->val <= cur->next->val)
                cur = cur->next;
            else{
                while(pre->next->val <= cur->next->val)
                    pre = pre->next;
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            pre = res;
        }
        return res->next;
    }
};