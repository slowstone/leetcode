class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode *> ts;
        ts.push(root);
        while(!ts.empty()){
            TreeNode* tmp = ts.top();
            ts.pop();
            if(tmp->left == NULL && tmp->right == NULL){
                res.push_back(tmp->val);
            }
            else{
                ts.push(tmp);
                if(tmp->right != NULL)
                    ts.push(tmp->right);
                if(tmp->left != NULL)
                    ts.push(tmp->left);
                tmp->left = NULL;
                tmp->right = NULL;
            }
        }
        return res;
    }
};