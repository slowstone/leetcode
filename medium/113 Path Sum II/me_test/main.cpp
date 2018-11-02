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
    void SubPathSum(TreeNode* root, int sum, vector<int> cur, vector<vector<int>>& res){
        if(root == NULL) return;
        if(root->left == NULL  && root->right == NULL){
            if(sum == root->val){
                cur.push_back(root->val);
                res.push_back(cur);
            }
            return;
        }
        cur.push_back(root->val);
        SubPathSum(root->left,sum - root->val, cur,res);
        SubPathSum(root->right,sum - root->val, cur , res);
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res; 
        if(root == NULL) return res;
        SubPathSum(root,sum,vector<int>(),res);
        return res;
    }
};