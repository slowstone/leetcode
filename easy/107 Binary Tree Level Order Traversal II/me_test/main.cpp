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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        vector<vector<int>> lres = levelOrderBottom(root->left);
        vector<vector<int>> rres = levelOrderBottom(root->right);
        int i = lres.size()-1,j = rres.size()-1;
        while(i >= 0 && j >= 0){
        	vector<int> tmp;
        	tmp.insert(tmp.end(),lres[i].begin(),lres[i].end());
        	tmp.insert(tmp.end(),rres[j].begin(),rres[j].end());
        	res.push_back(tmp);
        	i--;
        	j--;
        }
        while(i >= 0){
        	res.push_back(lres[i]);
        	i--;
        }
        while(j >= 0){
        	res.push_back(rres[j]);
        	j--;
        }
        reverse(res.begin(),res.end());
        res.push_back(vector<int>{root->val});
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
private:
	vector<vector<int>> levelOrder(TreeNode* root){
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> upres = levelOrder(root);
        reverse(upres.begin(),upres.end());
        return upres;
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root,0,res);
        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution {
private:
    int height(TreeNode * root){
        if(root == NULL) return 0;
        return max(height(root->left),height(root->right)) + 1;
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        vector<queue<TreeNode*>> stvec(2,queue<TreeNode*>());
        int h = height(root);
        vector<vector<int>> res(h,vector<int>());
        int cur = 0,pre = 1;
        h--;
        stvec[cur].push(root);
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
                h--;
            }
        }
        return res;
    }
};