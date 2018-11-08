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
    void searchRange(TreeNode * root, int k1, int k2, vector<int>& res){
        if(root == NULL) return;
        if(root->val == k1 || root->val == k2)
            res.push_back(root->val);
        if(root->val >= k2)
            searchRange(root->left,k1,k2,res);
        else if(root->val <= k1)
            searchRange(root->right,k1,k2,res);
        else{
            res.push_back(root->val);
            searchRange(root->left,k1,k2,res);
            searchRange(root->right,k1,k2,res);
        }
    }
public:
    /**
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        // write your code here
        vector<int> res;
        searchRange(root,k1,k2,res);
        return res;
    }
};


class Solution {
public:
    /**
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        // write your code here
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode *> tmp;
        TreeNode* cur = root;
        while(cur || !tmp.empty()){
            if(cur == NULL){
                cur = tmp.top();
                tmp.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
            while(cur != NULL && cur->val >= k1){
                if(cur->val <= k2)
                    tmp.push(cur);
                cur = cur->left;
            }
            if(cur != NULL){
                cur = cur->right;
            }
        }
        return res;
    }
};