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
    double nres = INT_MIN;
    TreeNode *tres = NULL;
    void help(TreeNode *root,int& num,int& sum){
        if(root == NULL) return;
        int ln = 0,rn = 0,ls = 0,rs = 0;
        help(root->left,ln,ls);
        help(root->right,rn,rs);
        num = ln + rn + 1;
        sum = ls + rs + root->val;
        double ave_s = double(sum) / num;
        if(ave_s > nres){
            nres = ave_s;
            tres = root;
        }
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        int sum = 0,num = 0;
        cout << nres << endl;
        help(root,sum,num);
        return tres;
    }
};

class Solution {
private:
    int cur_num = 0;
    int cur_sum = 0;
    TreeNode *tres = NULL;
    void help(TreeNode *root,int& num,int& sum){
        if(root == NULL) return;
        int ln = 0,rn = 0,ls = 0,rs = 0;
        help(root->left,ln,ls);
        help(root->right,rn,rs);
        num = ln + rn + 1;
        sum = ls + rs + root->val;
        if(tres == NULL || (sum * cur_num > cur_sum * num)){
            cur_num = num;cur_sum = sum;tres = root;
        }
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        int sum = 0,num = 0;
        help(root,sum,num);
        return tres;
    }
};