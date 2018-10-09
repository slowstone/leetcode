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
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return rob(root, l, r);
    }
    
    int rob(TreeNode* t, int &l, int &r){
        if(!t)
            return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = rob(t->left, ll, lr);
        r = rob(t->right, rl, rr);
        return max(t->val + ll + lr + rl + rr, l + r);
    }
};