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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tmp3 = 0;
        ListNode* root = NULL;
        ListNode* cur = NULL;
        while(l1 && l2){
            int tmp1 = l1->val;
            int tmp2 = l2->val;
            int sum = tmp1 + tmp2 + tmp3;
            if(cur == NULL){
                root = new ListNode(sum%10);
                cur = root;
            }
            else{
                cur->next = new ListNode(sum%10);
                cur = cur->next;
            }
            tmp3 = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int tmp = l1->val;
            int sum = tmp + tmp3;
            if(cur == NULL){
                root = new ListNode(sum%10);
                cur = root;
            }
            else{
                cur->next = new ListNode(sum%10);
                cur = cur->next;
            }
            tmp3 = sum/10;
            l1 = l1->next;
        }
        while(l2){
            int tmp = l2->val;
            int sum = tmp + tmp3;
            if(cur == NULL){
                root = new ListNode(sum%10);
                cur = root;
            }
            else{
                cur->next = new ListNode(sum%10);
                cur = cur->next;
            }
            tmp3 = sum/10;
            l2 = l2->next;
        }
        if(tmp3 != 0){
            if(cur == NULL){
                root = new ListNode(tmp3);
                cur = root;
            }
            else{
                cur->next = new ListNode(tmp3);
                cur = cur->next;
            }
        }
        return root;
    }
};