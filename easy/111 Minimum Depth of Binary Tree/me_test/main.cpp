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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int res = INT_MAX;
        if(root->left != NULL) res = minDepth(root->left);
        if(root->right != NULL) res = min(res,minDepth(root->right));
        res = res == INT_MAX ? 1 : res + 1;
        return res;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> tq;
       	tq.push(root);
       	int height = 0;
       	while(!tq.empty()){
       		int n = tq.size();
       		height++;
       		while(n != 0){
       			TreeNode *tmp = tq.front();
       			tq.pop();
       			if(tmp->left != NULL)
       				tq.push(tmp->left);
       			if(tmp->right != NULL)
       				tq.push(tmp->right);
       			if(tmp->left == NULL && tmp->right == NULL)
       				return height;
       			n--;
       		}
       	}
    }
};