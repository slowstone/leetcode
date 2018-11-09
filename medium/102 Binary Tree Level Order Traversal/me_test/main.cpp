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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        res.push_back(vector<int>{root->val});
        vector<vector<int>> lres = levelOrder(root->left);
        vector<vector<int>> rres = levelOrder(root->right);
        int i = 0;
        while(i < lres.size() && i < rres.size()){
            vector<int> tmp;
            tmp.insert(tmp.end(),lres[i].begin(),lres[i].end());
            tmp.insert(tmp.end(),rres[i].begin(),rres[i].end());
            res.push_back(tmp);
            i++;
        }
        while(i < lres.size()){
            res.push_back(lres[i]);
            i++;
        }
        while(i < rres.size()){
            res.push_back(rres[i]);
            i++;
        }
        return res;
    }
};

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root,0,res);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<queue<TreeNode*>> stvec(2,queue<TreeNode*>());
        vector<vector<int>> res;
        int cur = 0,pre = 1;
        stvec[cur].push(root);
        int h = 0;
        while(stvec[cur].size() != 0){
            if(res.size() == h)
                res.push_back({});
            TreeNode *ttmp = stvec[cur].front();
            stvec[cur].pop();
            res[h].push_back(ttmp->val);
            if(ttmp->left != NULL)
                stvec[pre].push(ttmp->left);
            if(ttmp->right != NULL)
                stvec[pre].push(ttmp->right);
            if(stvec[cur].size() == 0){
                pre = cur;
                cur = 1-cur;
                h++;
            }
        }
        return res;
    }
};