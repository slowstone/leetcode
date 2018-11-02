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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return vector<vector<int>> ();
        vector<vector<int>> res;
        vector<int> vi;
        help(root, sum, res, vi);
        return res;
    }
    
private:
    void help(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& vi) {
        if (!root) return;
        vi.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) res.push_back(vi);
        help(root->left, sum - root->val, res, vi);
        help(root->right, sum - root->val, res, vi);
        vi.pop_back();  //remove vi.pop_back() if not reference
    }
};