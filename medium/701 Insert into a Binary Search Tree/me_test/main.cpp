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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while(cur != NULL){
            pre = cur;
            if(cur->val > val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if(pre->val > val)
            pre->left = new TreeNode(val);
        else
            pre->right = new TreeNode(val);
        return root;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *tmp = new TreeNode(val);
        if(root == NULL) return tmp;
        if(root->val > val)
            root->left = insertIntoBST(root->left,val);
        else
            root->right = insertIntoBST(root->right,val);
        return root;
    }
};