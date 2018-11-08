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
    bool isValidBST(TreeNode* root,int& amin,int& amax){
        if(root->left == NULL && root->right == NULL){
            amin = root->val;
            amax = root->val;
            return true;
        }
        int lmax = INT_MIN, rmin = INT_MAX;
        bool l = true,r = true;
        if(root->left != NULL){
            l = isValidBST(root->left,amin,lmax);
            if(!l || lmax >= root->val)
                return false;
        }
        if(root->right != NULL){
            r = isValidBST(root->right,rmin,amax);
            if(!r || rmin <= root->val)
                return false;
        }
        amin = min(amin,root->val);
        amax = max(amax,root->val);
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        int amin = INT_MAX, amax = INT_MIN;
        return isValidBST(root,amin,amax);
    }
};

class Solution {
private:
    bool isValidBST(TreeNode* root, long l, long h){
        if(root == NULL) return true;
        if(root->val >= h || root->val <= l)
            return false;
        if(!isValidBST(root->left,l,root->val) || !isValidBST(root->right,root->val,h))
            return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
};
