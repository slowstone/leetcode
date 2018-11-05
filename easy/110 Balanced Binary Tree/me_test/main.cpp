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
    bool isBwithH(TreeNode* root,int &h){
        if(root == NULL) return true;
        int lh = 0,rh = 0;
        if(!isBwithH(root->left, lh)) return false;
        if(!isBwithH(root->right,rh)) return false;
        if(abs(lh - rh) > 1) return false;
        h = max(lh,rh) + 1;
        return true;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int h = 0;
        return isBwithH(root,h);
    }
};

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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if(abs(height(root->left)-height(root->right))>1) return false;
        return isBalanced(root->left) && isBalanced(root->right); 
    }
    
    int height(TreeNode* node) {
        if(!node) return 0;
        return max(height(node->left),height(node->right))+1;
    }
};