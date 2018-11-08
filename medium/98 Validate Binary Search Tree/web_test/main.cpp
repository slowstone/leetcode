class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        if(!root) return true;
        TreeNode* cur = root;
        int prev = INT_MIN;
        bool has_prev = false;
        while(cur||!stk.empty()){
            if(cur){
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                if(has_prev && cur->val<=prev){
                    return false;
                }
                prev = cur->val;
                has_prev = true;
                cur = cur->right;
            }
        }
        return true;
    }
};

class Solution {
private:
    bool isValid(TreeNode* root, long high, long low) 
    {
        if(!root)   return true;
        if(root->val >= high || root->val <= low)    return false;
        return isValid(root->left, root->val, low) && isValid(root->right, high, root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MAX, LONG_MIN);
    }
};