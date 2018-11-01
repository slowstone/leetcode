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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* cur = NULL;
        while(l1 != NULL && l2 != NULL){
            int tmp = 0;
            // cout << l1->val << " " << l2->val << endl;
            if(l1->val < l2->val){
                tmp = l1->val;
                l1 = l1->next;
            }
            else{
                tmp = l2->val;
                l2 = l2->next;
            }
            if(res == NULL){
                res = new ListNode(tmp);
                cur = res;
            }
            else{
                cur->next = new ListNode(tmp);
                cur = cur->next;
            }
        }
        if(l1 != NULL){
            if(res == NULL)
                res = l1;
            else
                cur->next = l1;
        }
            
        if(l2 != NULL){
            if(res == NULL)
                res = l2;
            else
                cur->next = l2;
        }
        return res;
    }
};

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while(l1 != NULL && l2 != NULL){
            int tmp = 0;
            // cout << l1->val << " " << l2->val << endl;
            if(l1->val < l2->val){
                tmp = l1->val;
                l1 = l1->next;
            }
            else{
                tmp = l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(tmp);
            cur = cur->next;
        }
        if(l1 != NULL){
            cur->next = l1;
        }
            
        if(l2 != NULL){
            cur->next = l2;
        }
        return res->next;
    }
};