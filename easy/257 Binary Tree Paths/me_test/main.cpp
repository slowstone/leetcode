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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return {};
        vector<string> res;
        if(root->left == NULL && root->right == NULL){
            res.push_back({to_string(root->val)});
        }
        else{
            vector<string> lr = binaryTreePaths(root->left);
            vector<string> rr = binaryTreePaths(root->right);
            for(auto r:lr)
                res.push_back(to_string(root->val) + "->" + r);
            for(auto r:rr)
                res.push_back(to_string(root->val) + "->" + r);
        }
        return res;
    }
};