class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> levels;
        levels.push(root);
        while (!levels.empty())
        {
            TreeNode* curNode = levels.top();
            levels.pop();
            if (curNode)
            {
                if (curNode->right || curNode->left)
                {
                    TreeNode *dummy = new TreeNode(curNode->val);
                    levels.push(dummy);
                    levels.push(curNode->right);
                    levels.push(curNode->left);
                }
                else
                {
                    result.push_back(curNode->val);
                }
            }
        }
        
        return result;
    }
};