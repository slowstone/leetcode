/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if(root == NULL) return NULL;
        // write your code here
        if(p->right != NULL){
            p = p->right;
            while(p->left != NULL) p = p->left;
            return p;
        }
        TreeNode *pre = NULL;
        TreeNode *cur = root;
        while(cur != p){
            if(cur->val > p->val){
                pre = cur;
                cur = cur->left;
            }
            else
                cur = cur->right;
        }
        return pre;
    }
};


class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if(root == NULL) return NULL;
        if(root->val > p->val){
            TreeNode * tmp = inorderSuccessor(root->left,p);
            if(tmp == NULL)
                return root;
        }
        else{
            return inorderSuccessor(root->right,p);
        }
    }
};