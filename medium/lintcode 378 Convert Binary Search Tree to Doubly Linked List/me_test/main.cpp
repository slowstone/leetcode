/**
  * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
 *         this->prev = this->next = NULL;
 *     }
 * } * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
private:
    void help(TreeNode * root,DoublyListNode * &end, DoublyListNode * &start){
        if(root == NULL) return;
        DoublyListNode *cur = new DoublyListNode(root->val);
        help(root->left,end,start);
        if(end != NULL){
            end->next = cur;
            cur->prev = end;
        }
        end = cur;
        if(start == NULL){
            start = end;
        }
        help(root->right,end,start);
    }
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode * bstToDoublyList(TreeNode * root) {
        // write your code here
        DoublyListNode * start = NULL;
        DoublyListNode * end = NULL;
        help(root,end,start);
        return start;
    }
};