class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur||!stk.empty()){
            if(cur){
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
            
        }
        return res;
    }
};