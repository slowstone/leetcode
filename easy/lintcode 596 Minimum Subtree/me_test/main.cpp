/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
private:
    int nres = INT_MAX;
    TreeNode *tres = NULL;
    int find(TreeNode *root){
        if(root == NULL) return 0;
        int sum = root->val + find(root->left) + find(root->right);
        if(sum < nres){
            nres = sum;
            tres = root;
        }
        return sum;
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        find(root);
        return tres;
    }
};