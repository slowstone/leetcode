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
    int subpathSum(TreeNode* root, int sum){
        //之前已经选过某一结点，之后必须都选取，不允许隔代
                //Have selected a node before, must be selected afterwards, not allowed for generations
        if(root == NULL) return 0;
        int res = sum == root->val ? 1 : 0;
        res += subpathSum(root->left, sum - root->val) + subpathSum(root->right, sum - root->val);
        return res;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        //之前没有选过某一结点，可以选择该节点或者不选用该节点
                //You have not selected a node before, you can choose this node or not use it.
        int res = sum == root->val ? 1 : 0;
        res += subpathSum(root->left, sum - root->val) + subpathSum(root->right, sum - root->val);
        res += pathSum(root->left, sum) + pathSum(root->right, sum);
        return res;
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
    int pathSum(TreeNode* root, int sum, bool flag = true) {
        //flag 用于判断之前是否已经选过节点，是前一个代码的简版
                //''flag'' is used to determine whether a node has been selected before, which is a short version of the previous code.
        if(root == NULL) return 0;
        int res = sum == root->val ? 1 : 0;
        res += pathSum(root->left, sum - root->val, false) + pathSum(root->right, sum - root->val, false);
        if(flag) res += pathSum(root->left, sum, true) + pathSum(root->right, sum, true);
        return res;
    }
};