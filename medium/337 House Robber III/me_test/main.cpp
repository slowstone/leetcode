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
    vector<int> subrob(TreeNode* root){
        if(root == NULL)
            return vector<int>(2,0);
        vector<int> leftvec = subrob(root->left);
        vector<int> rightvec = subrob(root->right);
        int tmp = root->val + leftvec[1] + rightvec[1];
        tmp = leftvec[0] + rightvec[0];
        vector<int>
    }
public:
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        return max(rob(root->left),rob(root->right)) + root->val;
    }
};