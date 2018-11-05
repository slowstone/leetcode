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
    void levelOrder(TreeNode* root,int level,vector<vector<int>> &res){
        if(root == NULL) return;
        if(level >= res.size())
            res.push_back({});
        res[level].push_back(root->val);
        levelOrder(root->left,level+1,res);
        levelOrder(root->right,level+1,res);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root,0,res);
        for(int i = 0;i < res.size();i++){
            if(i%2 != 0)
                reverse(res[i].begin(),res[i].end());
        }
        return res;
    }
};