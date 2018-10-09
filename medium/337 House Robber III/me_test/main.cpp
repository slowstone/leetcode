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
        vector<int> res = vector<int>(2,0);
        if(root == NULL)
            return res;
        vector<int> leftvec = subrob(root->left);
        vector<int> rightvec = subrob(root->right);
        int tmp = root->val + leftvec[1] + rightvec[1];
        res[0] = tmp;
        tmp = leftvec[0] + rightvec[0];
        res[1] = tmp;
        if(res[0] < res[1])
            res[0] = res[1];
        return res;
    }
public:
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        vector<int> leftvec = subrob(root->left);
        vector<int> rightvec = subrob(root->right);
        int tmp = root->val + leftvec[1] + rightvec[1];
        tmp = max((leftvec[0] + rightvec[0]),tmp);
        return tmp;
    }
};