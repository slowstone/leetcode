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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while(cur != NULL && cur->val != key){
            pre = cur;
            if(cur->val > key)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if(cur == NULL) return root;
        if(cur->left == NULL){
            if(pre == NULL)
                return cur->right;
            if(pre->val > key)
                pre->left = cur->right;
            else
                pre->right = cur->right;
        }
        else{
            TreeNode* tmp = cur;
            cur = cur->left;
            while(cur->right != NULL) cur = cur->right;
            cur->right = tmp->right;
            if(pre == NULL)
                return tmp->left;
            if(pre->val > key)
                pre->left = tmp->left;
            else
                pre->right = tmp->left;
        }
        return root;
    }
};