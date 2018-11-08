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
private:
    TreeNode* help(TreeNode* root){
        if(root == NULL) return NULL;
        TreeNode* le = help(root->left);
        TreeNode* re = help(root->right);
        if(le == NULL)
            return re == NULL ? root : re;
        le->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return re == NULL ? le : re;
    }
public:
    void flatten(TreeNode* root) {
        help(root);
    }
};

class Solution {
private:
    TreeNode *lastnode = NULL;
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        if(lastnode != NULL){
            lastnode->left = NULL;
            lastnode->right = root;
        }
        lastnode = root;
        TreeNode *r = root->right;
        flatten(root->left);
        flatten(r);
    }
};