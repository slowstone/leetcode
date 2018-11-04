class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode *> ts;
        ts.push(root);
        while(!ts.empty()){
            TreeNode* tmp = ts.top();
            ts.pop();
            if(tmp == NULL)
                continue;
            res.push_back(tmp->val);
            ts.push(tmp->right);
            ts.push(tmp->left);
        }
        return res;
    }
};