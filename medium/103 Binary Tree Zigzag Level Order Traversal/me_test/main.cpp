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
    void levelOrder(TreeNode* root,int level,vector<vector<int>> &res){
        if(root == NULL) return;
        if(level >= res.size())
            res.push_back({});
        res[level].push_back(root->val);
        levelOrder(root->left,level+1,res);
        levelOrder(root->right,level+1,res);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root,0,res);
        for(int i = 0;i < res.size();i++){
            if(i%2 != 0)
                reverse(res[i].begin(),res[i].end());
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<stack<TreeNode*>> stvec(2,stack<TreeNode*>());
        vector<vector<int>> res;
        int cur = 0,pre = 1;
        stvec[cur].push(root);
        int h = 0;
        bool flag = true;
        while(stvec[cur].size() != 0){
            if(res.size() == h)
                res.push_back({});
            TreeNode *ttmp = stvec[cur].top();
            stvec[cur].pop();
            res[h].push_back(ttmp->val);
            if(flag){
                if(ttmp->left != NULL)
                    stvec[pre].push(ttmp->left);
                if(ttmp->right != NULL)
                    stvec[pre].push(ttmp->right);
            }
            else{
                if(ttmp->right != NULL)
                    stvec[pre].push(ttmp->right);
                if(ttmp->left != NULL)
                    stvec[pre].push(ttmp->left);                
            }
            if(stvec[cur].size() == 0){
                pre = cur;
                cur = 1-cur;
                h++;
                flag = !flag;
            }
        }
        return res;
    }
};