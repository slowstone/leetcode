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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        vector<int> tmp = inorderTraversal(root->left);
        res.insert(res.end(),tmp.begin(),tmp.end());
        res.push_back(root->val);
        tmp = inorderTraversal(root-> right);
        res.insert(res.end(),tmp.begin(),tmp.end());
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode *> ts;
        ts.push(root);
        while(!ts.empty()){
            TreeNode* tmp = ts.top();
            ts.pop();
            if(tmp->right != NULL){
                ts.push(tmp->right);
            }
            if(tmp->left == NULL){
                res.push_back(tmp->val);
            }
            else{
                ts.push(tmp);
                ts.push(tmp->left);
            }
            tmp->right = NULL;
            tmp->left = NULL;
        }
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> ts;
        ts.push(root);
        while(!ts.empty()){
            TreeNode* tmp = ts.top();
            ts.pop();
            if(tmp == NULL){
                while(tmp == NULL && !ts.empty()){
                    tmp = ts.top();
                    ts.pop();
                }
                if(tmp != NULL)
                    res.push_back(tmp->val);
            }
            else{
                ts.push(tmp->right);
                ts.push(tmp);
                ts.push(tmp->left);
                tmp->right = NULL;
                tmp->left =NULL;
            }
        }
        return res;
    }
};